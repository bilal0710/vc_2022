#pragma once

#include <queue>
#include "gui.choiceType.h"

namespace Gui
{
    class CChoiceSystem
    {
        using InputQueue = std::queue<SChoiceType::Enum>;

    public:
        static CChoiceSystem& GetInstance()
        {
            static CChoiceSystem instance;
            return instance;
        };

        CChoiceSystem(const CChoiceSystem&) = delete;
        CChoiceSystem& operator = (const CChoiceSystem&) = delete;

    private:
        CChoiceSystem()
        {};

    public:

        void AddInput(SChoiceType::Enum _Input);
        SChoiceType::Enum GetNextInput();
        void RemoveNextInput();
        bool HasInputs() const;

    private:
        InputQueue m_ChoiceQueue;

    };

}