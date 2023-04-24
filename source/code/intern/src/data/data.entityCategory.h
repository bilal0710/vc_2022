
#pragma once

namespace Data
{
    struct SEntityCategory
    {
        enum Enum
        {
            Character,
            Ground,
            Obstacle,
            Finish,
            Cloud,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
