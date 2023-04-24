#pragma once
//#include "data.entityLink.h"
#include "data.metaEntity.h"

#include <array>

#include "../core/core_vector3.h"
#include "../core/core_id_manager.h"
#include "data.entityLink.h"


namespace Data
{
    class CEntity
    {
    public:

        enum Facet
        {
            GraphicsFacet,
            LogicFacet,
            NumberOfFacets
        };

    public:

        void SetFacet(Facet type, void* facet);
        void* GetFacet(Facet type);

    public:

        Core::CIDManager::BID id;
        Core::CVector3<float> position;
        Core::CVector3<float> size;
        Core::CAABB3<float> aabb;
        CMetaEntity* metaEntity;

    private:

        using FacetArray = std::array<void*, NumberOfFacets>;

    public:

        FacetArray facets;
        CEntityLink m_Link;

    private:

        friend class EntityLink;
        friend class EntityList;
    };
}
