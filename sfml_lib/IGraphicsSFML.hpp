#ifndef IGraphicsSFML_HPP
# define IGraphicsSFML_HPP

# include "../includes/Game.hpp"
# include "../includes/IGraphics.hpp"
# include "SFML/SFML-2.5.0-macOS-clang/include/SFML/Graphics.hpp"

class IGraphicsSFML : public IGraphics
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
        sf::Texture t4;        

        sf::Sprite sprite1;
        sf::Sprite sprite2;
        sf::Sprite sprite3;
        sf::Sprite sprite4;

      public:
        IGraphicsSFML();
        IGraphicsSFML(int n, int m);
        IGraphicsSFML(IGraphicsSFML const &ref);
        ~IGraphicsSFML();
        
        IGraphicsSFML &operator=(IGraphicsSFML const &ref);

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init);
        void DrawSnake(Snake &snake);
        Direction CheckEvent(Direction &dr);
        void DrawFruit(Fruit &fruit);
        void DrawObstacle(Snake & snake);
        void DrawMap(Border &border);
};

#endif