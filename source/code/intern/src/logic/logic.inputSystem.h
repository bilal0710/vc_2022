#pragma once

#include <queue>
#include "logic.inputType.h"

namespace Logic
{
    class CInputSystem
    {
        using InputQueue = std::queue<SInputType::Enum>;

    public:
        static CInputSystem& GetInstance()
        {
            static CInputSystem instance;
            return instance;
        };

        CInputSystem(const CInputSystem&) = delete;
        CInputSystem& operator = (const CInputSystem&) = delete;

    private:
        CInputSystem()
        {};

    public:
  
        void AddInput(SInputType::Enum _Input);
        SInputType::Enum GetNextInput();
        void RemoveNextInput();
        bool HasInputs() const;

    private:
        InputQueue m_InputQueue;

    };

}