#pragma once

namespace SmartGL
{
    namespace Maths
    {
        template<typename T>
        static T Clamp(const T &value, const T &min, const T &max)
        {
            return value < min ? min : (value > max ? max : value);
        }
    }
}
