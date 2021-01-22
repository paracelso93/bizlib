//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_COLOR_H
#define OPENGL_COLOR_H

namespace biz {
    struct ColorFloat {
        float r, g, b, a;

        ColorFloat() {
            r = g = b = a = 0.f;
        }

        ColorFloat(float r, float g, float b, float a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
    };

    struct Color {
        unsigned char r, g, b, a;
        Color() {
            r = g = b = a = 0;
        }

        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

        ColorFloat normalize() {
            return ColorFloat(
                    static_cast<float>(r) / 255.f,
                    static_cast<float>(g) / 255.f,
                    static_cast<float>(b) / 255.f,
                    static_cast<float>(a) / 255.f);
        }
    };
}

#endif //OPENGL_COLOR_H
