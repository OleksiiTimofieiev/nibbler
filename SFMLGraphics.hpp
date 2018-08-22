#ifndef SFMLGRAPHICS_HPP
# define SFMLGRAPHICS_HPP

# include "Game.hpp"
# include "IGraphics.hpp"

class SFMLGraphics : public IGraphics
{
    private:
        int N;
        int M;
        int size;
        int w;
        int h;

        sf::RenderWindow window;

        sf::Texture t1;
        sf::Texture t2;
        sf::Texture t3;

        sf::Sprite sprite1;
        sf::Sprite sprite2;
        sf::Sprite sprite3;

      public:
        SFMLGraphics();
        SFMLGraphics(SFMLGraphics const &ref);
        ~SFMLGraphics();
        
        SFMLGraphics &operator=(SFMLGraphics const &ref);

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init);
        void DrawSnake(Snake &snake);
        Direction CheckEvent(Direction &dr);
        void DrawFruit(Fruit &fruit);
        void DrawMap(Border &border);
};

#endif