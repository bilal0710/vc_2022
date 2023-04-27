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

		if (m_Up) {
			//std::cout << "No Ground" << std::endl;
			MovePlayer(Core::Float2(0.0f, -m_Step));
			return;
		}
		if (m_Down) {
			//std::cout << "No Ground" << std::endl;
			MovePlayer(Core::Float2(0.0f, m_Step));
			return;
		}
		if (!m_PlayerCollided  && !m_Climbing) {
			//std::cout << "No Ground" << std::endl;
			MovePlayer(Core::Float2(0.0f, m_Step));
			return;
		}

		Logic::CInputSystem& rInputSystem = Logic::CInputSystem::GetInstance();
		SInputType::Enum currentInput;

		while (rInputSystem.HasInputs())
		{
			currentInput = (rInputSystem.GetNextInput());

			switch (currentInput)
			{
			case SInputType::Enum::MoveUp:
				MovePlayer(Core::Float2(0.0f, -m_Step));
				break;
			case SInputType::Enum::MoveDown:
				MovePlayer(Core::Float2(0.0f, m_Step));
				break;
			case SInputType::Enum::MoveRight:
				MovePlayer(Core::Float2(m_Step, 0.0f));
				break;
			case SInputType::Enum::MoveLeft:
				MovePlayer(Core::Float2(-m_Step, 0.0f));
				break;
			default:
				break;
			}

			rInputSystem.RemoveNextInput();
		}
	}

	void Logic::CPlayPhase::MovePlayer(Core::Float2 _Step)
	{
		Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
		Data::CEntity* pPlayer = rPlayerSystem.GetPlayer();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		if (pPlayer != nullptr)
		{
			if (pPlayer->position[1] > 1200)
			{
				rEventSystem.FireEvent(2);
			}


			// Check Collisions
			Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
			auto Entities = rEntitySystem.GetAllEntities();

			std::vector<Data::CEntity*> collisionEntities;

			for (auto& Entity : Entities)
			{
				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 74, pPlayer->position[1] + 128, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{

					if (Entity->category == Data::SEntityCategory::Finish)
					{
						rEventSystem.FireEvent(2);
					}

					if (Entity->category == Data::SEntityCategory::Ladder && _Step[1] != 0.0f)
					{
			
						if (_Step[1] > 0) {
							m_Down = true;
						}
						else {
							m_Up = true;
						}
						m_PlayerCollided = false;
						m_Climbing = true;
						collisionEntities.push_back(Entity);
						//break;
					}
					if (Entity->category == Data::SEntityCategory::Obstacle)
					{
						cout << "Obstacle" << std::endl;
						m_PlayerCollided = true;
						m_Climbing = false;
						m_Down = false;
						m_Up = false;
						std::cout << "Obstacle" << std::endl;
						collisionEntities.push_back(Entity);
					}

					if (Entity->category == Data::SEntityCategory::Ground)
					{
						m_PlayerCollided = true;
						//m_Up = false;
						m_Down = false;
						m_Climbing = false;
						std::cout << "Ground" << std::endl;
						collisionEntities.push_back(Entity);
					}
				}
			}
			if (collisionEntities.empty())
			{
				m_PlayerCollided = false;
				m_Up = false;
				if (!m_Climbing) {
					rEventSystem.FireEvent(3);
					pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1] + m_Step, pPlayer->position[2]);
					pPlayer->aabb = Core::CAABB3<float>(
						Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
						Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
					);
				return;
				}
			}
			if (m_Up)
			{
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			if (m_Down && !m_PlayerCollided)
			{
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + +_Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			else {
				pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
			}

			//if (m_Climbing)
			//{
			//	pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
			//	pPlayer->aabb = Core::CAABB3<float>(
			//		Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
			//		Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
			//	);
			//	//return;
			//}


		}
	}


	void CPlayPhase::OnLeave()
	{
		m_PlayerCollided = true;
		//m_Climbing = false;
		std::cout << "OnLeave" << std::endl;
	}
}