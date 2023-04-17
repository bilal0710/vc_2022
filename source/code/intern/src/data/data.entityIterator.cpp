
#include "data_entity_iterator.h"
#include "data_entity_link.h"

#include <assert.h>

namespace Data
{
    CEntityIterator::CEntityIterator()
        : m_pLink(nullptr)
    {
    }

    // -----------------------------------------------------------------------------

    CEntityIterator::CEntityIterator(const CEntityIterator& _rOther)
        : m_pLink(_rOther.m_pLink)
    {
    }

    // -----------------------------------------------------------------------------

    CEntityIterator::CEntityIterator(CEntityLink* _pLink)
        : m_pLink(_pLink)
    {
    }

    // -----------------------------------------------------------------------------

    CEntity& CEntityIterator::operator * ()
    {
        assert(m_pLink != nullptr);

        return m_pLink->GetEntity();
    }

    // -----------------------------------------------------------------------------

    CEntity* CEntityIterator::operator -> ()
    {
        assert(m_pLink != nullptr);

        return &m_pLink->GetEntity();
    }
}
