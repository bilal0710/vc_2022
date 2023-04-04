#include "data/data.eventSystem.h"
#include <iostream>
#include "data/data.Event.h"
#include "data/data.EventListener.h"

namespace Data
{

    void CEventSystem::Register(CEvent::BTypeID type, CEventListener listener)
    {
        this->eventListeners.push_back(std::make_pair(type, listener));
    }

    void CEventSystem::Unregister(CEvent::BTypeID type, CEventListener listener)
    {
        std::list<std::pair<CEvent::BTypeID, CEventListener>>::iterator it;

        for (it = eventListeners.begin(); it != eventListeners.end(); ++it)
        {
            if (it->first == type && it->second == listener)
            {
                eventListeners.erase(it);

                break;
            }
        }
    }

    void CEventSystem::FireEvent(CEvent& event)
    {
        for (std::pair<CEvent::BTypeID, CEventListener> listener : eventListeners)
        {
            // only invoke when type id matches
            if (listener.first == event.GetType())
            {
                // dereference and invoke function pointer
                (*(listener.second))(event);
            }
        }
    }

    void CEventSystem::FireEvent(CEvent::BTypeID _Type)
    {
        CEvent* event = nullptr;
        try
        {
            event = new CEvent();
            event->SetType(_Type);
            FireEvent(*event);
        }
        catch (...)
        {
            delete event;
        }
    }

    //void CEventSystem::FireEvent(CEvent::BTypeID _Type, int _Data)
    //{
    //    CEvent* event = nullptr;
    //    try
    //    {
    //        event = new CEvent(_Type, _Data);
    //        FireEvent(*event);
    //    }
    //    catch (...)
    //    {
    //        delete event;
    //    }
    //}

    CEventSystem::~CEventSystem()
    {
    }

    CEventSystem::CEventSystem()
    {
    }
}