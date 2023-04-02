#pragma once

#include <tinyxml2.h>

#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"
#include "data.Entity.h"

namespace Data
{
    class CEntitySystem
    {
    public:
        static CEntitySystem& GetInstance()
        {
            static CEntitySystem instance;
            return instance;
        };

        CEntitySystem(const CEntitySystem&) = delete;
        CEntitySystem& operator = (const CEntitySystem&) = delete;

    public:
        int Initialize(tinyxml2::XMLDocument& _rMapEntity);
        std::vector<Data::Entity*> GetAllEntities();
        Entity& CreateEntity(std::string _Name);
        void DestroyEntity();
        void DestoryAllEntities();
        Entity& SearchEntity(std::string _Name);
        Entity& GetEntity(Core::CIDManager::BID _Id);
        bool ContainsEntity(std::string _Name);
        Core::CIDManager::BID GetEntityID(std::string _Name);

    private:
        CEntitySystem()
        {};

    private:
        Core::CIDManager m_IdManager;
        Core::CItemManager<Entity> m_ItemManager;
    };
}