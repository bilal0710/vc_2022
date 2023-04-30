#include "gui.commandSystem.h"

#include <iostream>
#include <assert.h>

namespace Gui
{

    void CCommandSystem::AddCommand(SCommendType::Enum _Input)
    {
        m_CommandQueue.push(_Input);
    }

    SCommendType::Enum CCommandSystem::GetNextCommand()
    {
        assert(!m_CommandQueue.empty());

        return m_CommandQueue.front();
    }

    void CCommandSystem::RemoveNextCommand()
    {
        assert(!m_CommandQueue.empty());
        m_CommandQueue.pop();
    }

    bool CCommandSystem::HasCommands() const
    {
        return !m_CommandQueue.empty();
    }
}

