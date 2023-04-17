
#pragma once

#include "data_entity_category.h"
#include "data_entity_iterator.h"
#include "data_sector.h"

namespace Data
{
    class CMap
    {
        public:

            CEntityIterator BeginEntity(Core::AABB2Float& _rAABB, SEntityCategory::Enum _Category);
            CEntityIterator NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB, SEntityCategory::Enum _Category);

            CEntityIterator BeginEntity(Core::AABB2Float& _rAABB);
            CEntityIterator NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB);

            CEntityIterator EndEntity();

        private:

            CSector m_Sectors[4 * 8];        // Use constants or create dynamic array
    };
}

