#include "sounds.hpp"

Sound::Sound()
{
    if(soundBuffer.loadFromFile(R"(Sounds\eat.ogg)"))
    {
        sound.setBuffer(soundBuffer);
    }
    else
        std::runtime_error("R(Sounds\eat.ogg does not exist)");
}

void Sound::play()
{
    sound.play();
}
