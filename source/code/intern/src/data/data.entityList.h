
#pragma once

#include "data.entityIterator.h"
#include "data.entityLink.h"

namespace Data
{
    class CEntityList
    {
        public:

            CEntityList();
           ~CEntityList();

        public:

            void Clear();

            bool IsEmpty() const;

        public:

            void PushBack(CEntity& _rEntity);
            CEntity& PopBack();

            void Erase(CEntity& _rEntity);

        public:

            CEntityIterator Begin();
            CEntityIterator End();

        private:

            CEntityLink m_Anchor;
    };
}
