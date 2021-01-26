//
// Created by edoardo biasio on 2021-01-24.
//

#include "sound.h"

namespace biz {

    irrklang::ISoundEngine* Sound::sound_engine = nullptr;

    Sound::Sound(const std::string& file) {
        this->name = file;
    }

    void Sound::set_looped(bool loop) {
        this->looped = loop;
    }

    void Sound::play() {
        const char* n = name.c_str();
        sound_engine->play2D(n, this->looped);
    }
}