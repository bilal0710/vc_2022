#include "gui.choiceSystem.h"

#include <iostream>
#include <assert.h>

namespace Gui
{

    void CChoiceSystem::AddInput(SChoiceType::Enum _Input)
    {
        m_ChoiceQueue.push(_Input);
    }

    SChoiceType::Enum CChoiceSystem::GetNextInput()
    {
        assert(!m_ChoiceQueue.empty());

        return m_ChoiceQueue.front();
    }

    void CChoiceSystem::RemoveNextInput()
    {
        assert(!m_ChoiceQueue.empty());
        m_ChoiceQueue.pop();
    }

    bool CChoiceSystem::HasInputs() const
    {
        return !m_ChoiceQueue.empty();
    }
}

