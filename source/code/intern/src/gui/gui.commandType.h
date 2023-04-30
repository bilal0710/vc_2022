#pragma once

namespace Gui
{
    struct SCommendType
    {
        enum Enum
        {
            MoveUp,
            MoveDown,
            MoveLeft,
            MoveRight,
            Enter,
            NumberOfTypes,
            Undefined = -1,
        };
    };
}