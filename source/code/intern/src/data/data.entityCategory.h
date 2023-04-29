
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
            Ladder,
            Needle,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
