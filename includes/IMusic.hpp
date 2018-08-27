#ifndef IMUSIC_HPP
# define IMUSIC_HPP

class IMusic
{
    public:
      virtual ~IMusic(){};
      virtual void playEating(void) = 0;
      virtual void playCollision(void) = 0;
};

#endif