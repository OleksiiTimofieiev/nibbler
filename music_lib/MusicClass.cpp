#include "MusicClass.hpp"

extern "C" IMusic *PlayMusic(void)
{
    return (new Mus());
}

Mus::Mus(){}
Mus::Mus(Mus const &ref) { *this = ref; }
Mus::~Mus() {}

Mus &Mus::operator=(Mus const &ref)
{
    (void)ref;
    return *this;
}

void Mus::playEating(void)
{
    system("say oum&");
}

void Mus::playCollision(void)
{
    system("say ou&");
}
