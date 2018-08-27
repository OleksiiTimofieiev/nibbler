#ifndef MUSICCLASS_HPP
#define MUSICCLASS_HPP

#include "../includes/IMusic.hpp"
#include <iostream>

class Mus : public IMusic
{
    public:
      Mus();
      ~Mus();
      Mus(Mus const &ref);

      Mus &operator=(Mus const &ref);

      void playEating(void);
      void playCollision(void);
  };

#endif
