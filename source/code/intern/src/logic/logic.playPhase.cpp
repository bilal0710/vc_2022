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
	}

	void CPlayPhase::OnRun()
	{


		if (m_PlayerCanMoveUp) {
			MovePlayer(Core::Float2(0.0f, -m_Step));
			return;
		}
		if (m_PlayerCanMoveDown) {
			MovePlayer(Core::Float2(0.0f, m_Step));
			return;
		}
		if (!m_PlayerTouchedGround) {
			MovePlayer(Core::Float2(0.0f, m_Step));
			return;
		}

		Logic::CInputSystem& rInputSystem = Logic::CInputSystem::GetInstance();
		SInputType::Enum currentInput;

		while (rInputSystem.HasInputs())
		{
			currentInput = (rInputSystem.GetNextInput());
			m_Command = (rInputSystem.GetNextInput());

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

		bool PlayerCollidedWithGround = true;
		bool PlayerCollidedWithObstacle = false;
		m_PlayerCanMoveDown = false;
		m_PlayerCanMoveUp = false;

		if (pPlayer != nullptr)
		{
			if (pPlayer->position[1] > 1600)
			{
				rEventSystem.FireEvent(2);
			}


			// Check Collisions
			Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
			std::vector<Data::CEntity*> Entities = rEntitySystem.GetAllEntities();

			std::vector<Data::CEntity*> collisionEntities;

			for (auto& Entity : Entities)
			{
				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 74, pPlayer->position[1] + 128, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{
					m_PlayerTouchedGround = true;
					if (Entity->category == Data::SEntityCategory::Ladder)
					{
						collisionEntities.push_back(Entity);

						if (Entity->facets[0] && _Step[1] < 0.0f)
						{
							m_PlayerCanMoveUp = true;
						}
						if (_Step[1] > 0)
						{
							m_PlayerCanMoveDown = true;
						}
						break;
					}
				}
			}
			for (auto& Entity : Entities)
			{
				m_PlayerTouchedGround = true;
				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 100, pPlayer->position[1] + 128, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{

					if (Entity->category == Data::SEntityCategory::Finish)
					{
						rEventSystem.FireEvent(2);
					}
					if (Entity->category == Data::SEntityCategory::Needle)
					{
						rEventSystem.FireEvent(2);
					}

					if (Entity->category == Data::SEntityCategory::Obstacle)
					{
						collisionEntities.push_back(Entity);
						m_PlayerCanMoveDown = false;

						if (Entity->position[0] >= pPlayer->position[0] 
							&& Entity->position[1] == pPlayer->position[1]
							&& m_Command == SInputType::Enum::MoveRight) {
							PlayerCollidedWithObstacle = true;
						}
						if (Entity->position[0] <= pPlayer->position[0]
							&& Entity->position[1] == pPlayer->position[1]
							&& m_Command == SInputType::Enum::MoveLeft) {
							PlayerCollidedWithObstacle = true;
						}
					}

					if (Entity->category == Data::SEntityCategory::Ground)
					{
						m_PlayerCanMoveDown = false;
						PlayerCollidedWithGround = false;
						collisionEntities.push_back(Entity);
					}
				}
			}

			if (collisionEntities.empty())
			{
				m_PlayerTouchedGround = false;
				rEventSystem.FireEvent(3);
				pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1] + m_Step, pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			if (m_PlayerCanMoveUp)
			{
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			if (m_PlayerCanMoveDown && PlayerCollidedWithGround)
			{
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			else if(!PlayerCollidedWithObstacle){
				pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
			}

		}
	}

	void CPlayPhase::OnLeave()
	{
		m_PlayerTouchedGround = true;
	}

}