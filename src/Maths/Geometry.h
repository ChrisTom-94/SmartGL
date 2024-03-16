#pragma once

#include "Maths/Constants.h"

#include "glm/glm.hpp"

namespace SmartGL
{
    namespace Maths
    {
        template<typename T>
        static T Radians(T degrees)
        {
            return degrees * PI / 180.0f;
        }

        template<typename T>
        static T Degrees(T radians)
        {
            return radians * 180.0f / PI;
        }

        template<typename T>
        static float Dot(const T &a, const T &b)
        {
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        template<typename T>
        static T Cross(const T &a, const T &b)
        {
            return T(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
        }

        template<typename T>
        static T ProjectPointOnPlane(const T &point, const T &planeNormal, const T &planePoint)
        {
            T w = point - planePoint;
            auto d = dot(planeNormal, w);
            return point - d * planeNormal;
        }
    }
}
