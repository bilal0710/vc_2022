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
        int m_Data;

    public:
        int GetData() {
            return m_Data;
        }

        void SetData(int _Data) {
            m_Data=  _Data;
        }

    };
}