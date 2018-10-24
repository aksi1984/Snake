#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <exception>

class Sound
{
public:
    Sound();

    void play();

private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
};

#endif // SOUNDS_HPP
