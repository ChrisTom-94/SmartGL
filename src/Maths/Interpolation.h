#pragma once

#include "glm/glm.hpp"

namespace SmartGL
{
    namespace Maths
    {
        template<typename T>
        static T Lerp(const T &a, const T &b, float t)
        {
            return a + t * (b - a);
        }

        template<typename T>
        static T InversedLerp(const T &a, const T &b, const T &value)
        {
            return (value - a) / (b - a);
        }
    }
}
