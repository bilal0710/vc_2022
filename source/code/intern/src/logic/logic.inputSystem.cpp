#include "logic.inputSystem.h"

#include <iostream>
#include <assert.h>

namespace Logic
{
  
    void CInputSystem::AddInput(SInputType::Enum _Input)
    {
        m_InputQueue.push(_Input);
    }

    SInputType::Enum CInputSystem::GetNextInput()
    {
        assert(!m_InputQueue.empty());

        return m_InputQueue.front();
    }

    void CInputSystem::RemoveNextInput()
    {
        assert(!m_InputQueue.empty());
        m_InputQueue.pop();
    }

    bool CInputSystem::HasInputs() const
    {
        return !m_InputQueue.empty();
    }
}

