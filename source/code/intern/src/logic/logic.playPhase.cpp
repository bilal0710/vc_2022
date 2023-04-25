#include "logic.playPhase.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.entityCategory.h"
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

	void CPlayPhase::OnRun(Core::Float3 orientation)
	{
		//cout << "Logic::PlayPhase::InternOnRun" << std::endl;
		//cout << "------------------------" << std::endl;

		Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
		Data::CEntity* pPlayer = rPlayerSystem.GetPlayer();
		Logic::CInputSystem& rInputSystem = Logic::CInputSystem::GetInstance();

		Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();

		std::cout << "bool = " << rInputSystem.HasInputs() << std::endl;

		auto Entities = rEntitySystem.GetAllEntities();

		for (auto& Entity : Entities)
		{
			if (Entity->category == Data::SEntityCategory::Finish) {
				//std::cout << "FINISH Cat" << std::endl;

				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{

					cout << "Logic:: Data::SEntityCategory::Finish"<< endl;

					if (Entity->category == Data::SEntityCategory::Finish)
					{
						/* playerCollidedWithFinish = true;*/
						std::cout << "FINISH HIT" << std::endl;
						//Game::PlayPhase::GetInstance().finishedMap = true;
					}
				}
			}

		}

	}

	void CPlayPhase::OnLeave()
	{}
}