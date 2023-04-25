#pragma once

namespace Logic
{
    struct SInputType
    {
        enum Enum
        {
            MoveUp,
            MoveDown,
            MoveLeft,
            MoveRight,
            NumberOfTypes,
            Undefined = -1,
        };
    };
}