#pragma once

#include "data.event.h"
#include "data.eventListener.h"
#include <list>
#include <map>
#include <forward_list>


namespace Data
{
    class CEventSystem
    {
    public:
        static CEventSystem& GetInstance() { 
            static CEventSystem instance;
            return instance;
        };

    public:
        void Register(CEvent::BTypeID _Type, CEventListener _rListener);
        void Unregister(CEvent::BTypeID _Type, CEventListener _rListener);
        void FireEvent(CEvent::BTypeID _Type);
        void FireEvent(CEvent::BTypeID _Type, int _Data);
        //void FireEvent(CEvent::BTypeID _Type, int _Data);

    private:
        CEventSystem();
        ~CEventSystem();
        void FireEvent(CEvent& _rEvent);
        void FireEvent(CEvent& _rEvent, int _Data);

    private:
        CEventSystem(const CEventSystem&) = delete;
        CEventSystem& operator=(const CEventSystem&) = delete;

    public:
        std::list<std::pair<CEvent::BTypeID, CEventListener>> eventListeners;
    };
}