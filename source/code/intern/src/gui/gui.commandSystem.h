#pragma once


#include <queue>
#include "gui.commandType.h"

namespace Gui
{
    class CCommandSystem
    {
        using CommandQueue = std::queue<SCommendType::Enum>;

    public:
        static CCommandSystem& GetInstance()
        {
            static CCommandSystem instance;
            return instance;
        };

        CCommandSystem(const CCommandSystem&) = delete;
        CCommandSystem& operator = (const CCommandSystem&) = delete;

    private:
        CCommandSystem()
        {};

    public:

        void AddCommand(SCommendType::Enum _Input);
        SCommendType::Enum GetNextCommand();
        void RemoveNextCommand();
        bool HasCommands() const;

    private:
        CommandQueue m_CommandQueue;

    };

}