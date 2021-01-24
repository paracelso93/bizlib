//
// Created by edoardo biasio on 2021-01-24.
//

#include "sound.h"

namespace biz {

    irrklang::ISoundEngine* Music::sound_engine = nullptr;

    Music::Music(const std::string& file) {
        this->name = file;
    }

    void Music::set_looped(bool loop) {
        this->looped = loop;
    }

    void Music::play() {
        const char* n = name.c_str();
        sound_engine->play2D(n, this->looped);
    }
}