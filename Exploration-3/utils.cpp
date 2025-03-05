#include "utils.h"

namespace robot
{
    float degrees_to_radians(int degrees)
    {
        return (3.14 / 180) * degrees;
    }

    float degrees_to_radians(float degrees)
    {
        return (3.14 / 180) * degrees;
    }
}