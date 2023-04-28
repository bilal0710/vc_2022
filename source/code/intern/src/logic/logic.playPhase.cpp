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

		if (m_CanMoveUp) {
			std::cout << "if Up" << std::endl;
			MovePlayer(Core::Float2(0.0f, -m_Step));
			return;
		}
		if (m_CanMoveDown) {
			std::cout << "if Down" << std::endl;
			MovePlayer(Core::Float2(0.0f, m_Step));
			return;
		}
		if (!m_PlayerCollidedWithObject) {
			std::cout << "No Colide" << std::endl;
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
		bool PlayerCollidedWithGround = true;
		m_CanMoveDown = false;
		m_CanMoveUp = false;
		if (pPlayer != nullptr)
		{
			if (pPlayer->position[1] > 1200)
			{
				rEventSystem.FireEvent(2);
			}


			// Check Collisions
			Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
			std::vector<Data::CEntity*> Entities = rEntitySystem.GetAllEntities();

			std::vector<Data::CEntity*> collisionEntities;

			//forLoop(Entities, &collisionEntities, _Step);


			for (auto& Entity : Entities)
			{
				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 74, pPlayer->position[1] + 128, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{
					m_PlayerCollidedWithObject = true;
					if (Entity->category == Data::SEntityCategory::Ladder)
					{
						//std::cout << "canCollide= " << Entity->canCollide << std::endl;
						collisionEntities.push_back(Entity);

						if (Entity->canCollide && _Step[1] < 0.0f)
						{
							m_CanMoveUp = true;
						}
						if (_Step[1] > 0)
						{
							m_CanMoveDown = true;
						}
						break;
					}
				}
			}
			for (auto& Entity : Entities)
			{
				m_PlayerCollidedWithObject = true;
				if (Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 74, pPlayer->position[1] + 128, pPlayer->position[2])
				).Intersects(Entity->aabb))
				{

					if (Entity->category == Data::SEntityCategory::Finish)
					{
						rEventSystem.FireEvent(2);
					}

					if (Entity->category == Data::SEntityCategory::Obstacle)
					{
						collisionEntities.push_back(Entity);
					}

					if (Entity->category == Data::SEntityCategory::Ground)
					{
						m_CanMoveDown = false;
						PlayerCollidedWithGround = false;
						collisionEntities.push_back(Entity);
					}
				}
			}

			if (collisionEntities.empty())
			{
				m_PlayerCollidedWithObject = false;
				rEventSystem.FireEvent(3);
				pPlayer->position = Core::Float3(pPlayer->position[0] + _Step[0], pPlayer->position[1] + m_Step, pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			if (m_CanMoveUp)
			{
				std::cout << "move up" << std::endl;
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
				pPlayer->aabb = Core::CAABB3<float>(
					Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
					Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
				);
				return;
			}
			if (m_CanMoveDown && PlayerCollidedWithGround)
			{
				std::cout << "move down" << std::endl;
				pPlayer->position = Core::Float3(pPlayer->position[0], pPlayer->position[1] + _Step[1], pPlayer->position[2]);
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

		}
	}

	//void CPlayPhase::forLoop(std::vector<Data::CEntity*> Entities,
	//	std::vector<Data::CEntity*>* collisionEntities,
	//	Core::Float2 _Step)
	//{
	//	Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
	//	Data::CEntity* pPlayer = rPlayerSystem.GetPlayer();
	//	for (auto& Entity : Entities)
	//	{
	//		if (Core::CAABB3<float>(
	//			Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
	//			Core::Float3(pPlayer->position[0] + 74, pPlayer->position[1] + 128, pPlayer->position[2])
	//		).Intersects(Entity->aabb))
	//		{
	//			m_PlayerCollided = true;
	//			if (Entity->category == Data::SEntityCategory::Ladder)
	//			{
	//				std::cout << "canCollide= " << Entity->canCollide << std::endl;
	//				collisionEntities->push_back(Entity);

	//				if (Entity->canCollide && _Step[1] != 0.0f)
	//				{
	//					//	m_Climbing = true;
	//					if (_Step[1] > 0)
	//					{
	//						m_Down = true;
	//					}
	//					else {
	//						m_Up = true;
	//					}
	//				}
	//				break;
	//			}
	//			if (Entity->category == Data::SEntityCategory::Finish)
	//			{
	//				//rEventSystem.FireEvent(2);
	//			}

	//			if (Entity->category == Data::SEntityCategory::Obstacle)
	//			{
	//				cout << "Obstacle" << std::endl;
	//				m_Down = false;
	//				m_Up = false;
	//				std::cout << "Obstacle" << std::endl;
	//				collisionEntities->push_back(Entity);
	//			}

	//			if (Entity->category == Data::SEntityCategory::Ground)
	//			{
	//				m_Down = false;
	//				m_Climbing = false;
	//				collisionEntities->push_back(Entity);
	//			}
	//		}
	//	}
	//}

	void CPlayPhase::OnLeave()
	{
		m_PlayerCollidedWithObject = true;
		//m_Climbing = false;
		std::cout << "OnLeave" << std::endl;
	}

}