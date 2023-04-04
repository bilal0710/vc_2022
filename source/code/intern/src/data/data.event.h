#pragma once

namespace Data
{
    class CEvent
    {
    public:
        using BTypeID = int;

    public:
        void SetType(BTypeID _Type);
        BTypeID GetType() const;

    protected:
        BTypeID m_Type;

    protected:
        //CEvent();
        //virtual ~CEvent();
    };
}