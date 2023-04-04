#include "data.event.h"

namespace Data
{
    void Data::CEvent::SetType(BTypeID _Type)
    {
        this->m_Type = _Type;
    }

    Data::CEvent::BTypeID Data::CEvent::GetType() const
    {
        return this->m_Type;
    }
  
}