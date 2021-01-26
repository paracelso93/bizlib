//
// Created by edoardo biasio on 2021-01-24.
//

#ifndef OPENGL_SOUND_H
#define OPENGL_SOUND_H

#include "libs.h"

namespace biz {

    class Sound {
    public:
        Sound(const std::string& file);
        void set_looped(bool loop);
        void play();
        static irrklang::ISoundEngine* sound_engine;
    private:
        std::string name;
        bool looped;
    };
}

#endif //OPENGL_SOUND_H
