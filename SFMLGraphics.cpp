#include "SFMLGraphics.hpp"

SFMLGraphics::SFMLGraphics() : N(50), M(50), size(16), w(size * N), h(size * M) {

    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");

    sprite1.setTexture(t1);
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);
}

SFMLGraphics::SFMLGraphics(SFMLGraphics const &ref) { *this = ref; }
SFMLGraphics::~SFMLGraphics() {}

SFMLGraphics &SFMLGraphics::operator=(SFMLGraphics const &ref) {

    this->N = ref.N;
    this->M = ref.M;
    this->size = ref.size;
    this->w = ref.w;
    this->h = ref.h;
    this->t1 = ref.t1;
    this->t2 = ref.t2;
    
    return *this;
}

void SFMLGraphics::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init)
{
    Border bor;

    (void)score;
    (void)init;
    DrawMap(bor);

        // std::vector<std::pair<int, int> > _buf;

        // _buf = snake.getObstacleCoords();

        // for (int i = 0; i < 5; i++)
        // {
        //     std::cout << _buf[i].first << std::endl;
        // }

    DrawSnake(snake);
    DrawFruit(fruit);
    window.display();
}

void SFMLGraphics::DrawFruit(Fruit &fruit)
{
    std::pair<int, int> crd = fruit.getCoords();
    sprite2.setPosition(crd.first * size, crd.second * size);
    window.draw(sprite2);
}

void SFMLGraphics::DrawSnake(Snake &snake)
{
    std::pair<int, int> head = snake.getHeadCoords();
    std::vector<std::pair<int, int>> tail = snake.getTailCoords();

    sprite3.setPosition(head.first * size, head.second * size);
    window.draw(sprite3);
    for (int i = 0; i < snake.getTailLen(); i++)
    {
        sprite2.setPosition(tail[i].first * size, tail[i].second * size);
        window.draw(sprite2);
    }
}

Direction SFMLGraphics::CheckEvent(Direction &dr)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        dr = left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        dr = right;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        dr = down;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        dr = up;
    return (dr);
}

void SFMLGraphics::DrawMap(Border &border)
{
    (void)border;
    sf::Event e;

    window.create(sf::VideoMode(w, h), "SSSNAKE");

    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sprite1.setPosition(i * size, j * size);
            window.draw(sprite1);
        }
    }
}