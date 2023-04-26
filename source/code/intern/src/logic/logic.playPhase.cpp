#include "logic.playPhase.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.entityCategory.h"
#include "../data/data.eventSystem.h"
#include "logic/logic.inputSystem.h"

#include <iostream>


using namespace std;

namespace Logic
{
	void CPlayPhase::OnEnter()
	{
		cout << "Logic::PlayPhase::InternOnEnter" << std::endl;
		cout << "------------------------" << std::endl;
	}

	void CPlayPhase::OnRun()
	{
		//cout << "Logic::PlayPhase::InternOnRun" << std::endl;
		//cout << "------------------------" << std::endl;

		Logic::CInputSystem& rInputSystem = Logic::CInputSystem::GetInstance();
		SInputType::Enum currentInput;

		while (rInputSystem.HasInputs())
		{
			currentInput = (rInputSystem.GetNextInput());

			switch (currentInput)
			{
			case SInputType::Enum::MoveUp:
				MovePlayer(Core::Float2(0.0f, -2.0f));
				break;
			case SInputType::Enum::MoveDown:
				MovePlayer(Core::Float2(0.0f, 2.0f));
				break;
			case SInputType::Enum::MoveRight:
				MovePlayer(Core::Float2(2.0f, 0.0f));
				break;
			case SInputType::Enum::MoveLeft:
				MovePlayer(Core::Float2(-2.0f, 0.0f));
				break;
			default:
				break;
			}

			rInputSystem.RemoveNextInput();
		}


	}

	static void EventCallBack(Data::CEvent& data) {
		// std::cout << "ABC" << std::endl;

	}

	void Logic::CPlayPhase::MovePlayer(Core::Float2 _Step)
	{
		Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
		Data::CEntity* pPlayer = rPlayerSystem.GetPlayer();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		if (pPlayer != nullptr)
		{
			// Check Collisions
			// TODO: This needs to replaced with the proper EntityMap System call with the new aabb after the move (massive performance increase)
			Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
			auto Entities = rEntitySystem.GetAllEntities();

			std::vector<Data::CEntity*> collisionEntities;

			bool playerCollidedWithFinish = false;

			for (auto& Entity : Entities)
			{
				if (Entity->category == Data::SEntityCategory::Finish) {

					if (Core::CAABB3<float>(
						Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
						Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
					).Intersects(Entity->aabb))
					{

						cout << "Logic:: Data::SEntityCategory::Finish" << endl;

						if (Entity->category == Data::SEntityCategory::Finish)
						{
							rEventSystem.Register(Data::CEvent::BTypeID(0), &EventCallBack);
							rEventSystem.FireEvent(1);
							std::cout << "FINISH HIT" << std::endl;
						}
					}
				}

			}

			if (collisionEntities.empty())
			{
				pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
			}
			else
			{
				std::cout << collisionEntities.size() << std::endl;
			}

		}
	}


	void CPlayPhase::OnLeave()
	{}
}