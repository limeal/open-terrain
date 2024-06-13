/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <vector>
#include <stdexcept>
#include <string>

#pragma once

namespace OpenTerrain
{

    // Template class
    template <typename T, int S = 2>
    class Vector
    {
    public:
        Vector(std::vector<T> pos) : m_pos(pos) {}
        ~Vector() = default;

        T &getPos(int index) { return m_pos[index]; }
        const T getPos(int index) const { return m_pos[index]; }

        // Overload operator
        Vector operator+(const Vector &v) const
        {
            if (v._size != _size)
                throw std::invalid_argument("Vector size mismatch");

            std::vector<T> new_pos(S);
            for (int i = 0; i < S; i++)
            {
                new_pos[i] = m_pos[i] + v.m_pos[i];
            }
            return Vector(new_pos);
        }

        Vector operator-(const Vector &v) const
        {
            if (v._size != _size)
                throw std::invalid_argument("Vector size mismatch");

            std::vector<T> new_pos(S);
            for (int i = 0; i < S; i++)
            {
                new_pos[i] = m_pos[i] - v.m_pos[i];
            }
            return Vector(new_pos);
        }

        Vector operator*(const Vector &v) const
        {
            if (v._size != _size)
                throw std::invalid_argument("Vector size mismatch");

            std::vector<T> new_pos(S);
            for (int i = 0; i < S; i++)
            {
                new_pos[i] = m_pos[i] * v.m_pos[i];
            }
            return Vector(new_pos);
        }

        bool operator==(const Vector &v) const
        {
            if (v._size != _size)
                throw std::invalid_argument("Vector size mismatch");

            int count = 0;
            for (int i = 0; i < S; i++)
            {
                if (m_pos[i] == v.m_pos[i])
                    count++;
            }

            return count == S;
        }

    protected:
        std::vector<T> m_pos;

    private:
        T _size = S;
    };

    class Vector2 : public Vector<float, 2>
    {
    public:
        Vector2(float x, float y) : Vector<float, 2>({x, y}) {}
        Vector2(::Vector2 v) : Vector<float, 2>({v.x, v.y}) {}
        ~Vector2() = default;

        ::Vector2 operator~()
        {
            return {static_cast<float>(m_pos[0]), static_cast<float>(m_pos[1])};
        }

        float &x() { return m_pos[0]; }
        float &y() { return m_pos[1]; }
    };

    class Vector3 : public Vector<float, 3>
    {
    public:
        Vector3(float x, float y, float z) : Vector<float, 3>({x, y, z}) {}
        Vector3(::Vector3 v) : Vector<float, 3>({v.x, v.y, v.z}) {}
        ~Vector3() = default;

        ::Vector3 toRaylibVector3() const
        {
            return {static_cast<float>(m_pos[0]), static_cast<float>(m_pos[1]), static_cast<float>(m_pos[2])};
        }

        // Operator overload
        ::Vector3 operator~()
        {
            return {static_cast<float>(m_pos[0]), static_cast<float>(m_pos[1]), static_cast<float>(m_pos[2])};
        }

        std::string toString() const
        {
            return "(" + std::to_string((int)m_pos[0]) + "," + std::to_string((int)m_pos[1]) + "," + std::to_string((int)m_pos[2]) + ")";
        }

        float &x() { return m_pos[0]; }
        float &y() { return m_pos[1]; }
        float &z() { return m_pos[2]; }

        struct HashFunction
        {
            size_t operator()(const Vector3 &vector) const
            {
                // Use the toString
                return std::hash<std::string>()(vector.toString());
            }
        };
    };
}