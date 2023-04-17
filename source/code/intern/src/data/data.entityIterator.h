
#pragma once

namespace Data
{
    class CEntity;
    class CEntityLink;
    class CEntityList;
}

namespace Data
{
    class CEntityIterator
    {
        public:

            CEntityIterator();
            CEntityIterator(const CEntityIterator& _rOther);

        public:

            CEntity& operator * ();
            CEntity* operator -> ();

        private:

            CEntityLink* m_pLink;

        private:

            CEntityIterator(CEntityLink* _pLink);

        private:

            friend class CEntityList;
    };
}
