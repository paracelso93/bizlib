//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_MATH_H
#define OPENGL_MATH_H

namespace biz {
#define PI 3.14159265359

    template<typename T>
    struct Vector2 {
        T x, y;

        Vector2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        Vector2(const Vector2 &other) {
            this->x = other.x;
            this->y = other.y;
        }

        Vector2() {
            this->x = 0;
            this->y = 0;
        }

        Vector2 operator +(const Vector2 &other) {
            return Vector2(this->x + other.x, this->y + other.y);
        }

        Vector2 operator -(const Vector2 &other) {
            return Vector2(this->x - other.x, this->y - other.y);
        }

        Vector2 operator *(const T value) {
            return Vector2(this->x * value, this->y * value);
        }

        Vector2 operator /(const T value) {
            return Vector2(this->x / value, this->y / value);
        }

        Vector2 &operator =(const Vector2 &other) {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        bool operator ==(const Vector2 &other) {
            return (this->x == other.x) && (this->y == other.y);
        }
    };

    template<typename T>
    struct Rect {
        Vector2<T> position;
        Vector2<T> size;

        Rect() {
            position = Vector2<T>();
            size = Vector2<T>();
        };

        Rect(Vector2<T> position, Vector2<T> size) {
            this->position = position;
            this->size = size;
        }

        Rect(T x, T y, T w, T h) {
            this->position = Vector2<T>(x, y);
            this->size = Vector2<T>(w, h);
        }

        Rect(const Rect &other) {
            this->position = other.position;
            this->size = other.size;
        }

        Rect& operator =(const Rect &other) {
            this->position = other.position;
            this->size = other.size;
            return *this;
        }

        bool operator ==(const Rect &other) {
            return (this->position == other.position) && (this->size == other.size);
        }
    };

    static inline int nearest_power(int value, int power) {
        int start = 1;
        while (start < value) value *= power;
        return start;
    }
}

#endif //OPENGL_MATH_H
