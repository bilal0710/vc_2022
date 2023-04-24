#include "logic.playPhase.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.entityCategory.h"
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

        Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
        auto Entities = rEntitySystem.GetAllEntities();

        for (auto& Entity : Entities)
        {
            if (Entity->category == Data::SEntityCategory::Finish) {
                std::cout << "FINISH Cat" << std::endl;
            }

            if (Core::CAABB3<float>(
                Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
                Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2])
            ).Intersects(Entity->aabb)) {

              // cout << "Logic::PlayPhase::name= " << Entity->metaEntity->name << endl;
         

                if (Entity-> category == Data::SEntityCategory::Finish)
                {
                   /* playerCollidedWithFinish = true;*/
                    std::cout << "FINISH HIT" << std::endl;
                    //Game::PlayPhase::GetInstance().finishedMap = true;
                }
            }

        }

    }

    void CPlayPhase::OnLeave()
    {}
}