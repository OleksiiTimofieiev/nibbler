#include "SFMLGraphics.hpp"

SFMLGraphics::SFMLGraphics() : N(0), M(0), size(16), w(size * N), h(size * M) {

    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");
    t4.loadFromFile("images/black.png");

    sprite1.setTexture(t1);
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);
    sprite4.setTexture(t4);
}

SFMLGraphics::SFMLGraphics(int n, int m) : N(n), M(m), size(16), w(size * N), h(size * M)
{

    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");
    t4.loadFromFile("images/black.png");

    sprite1.setTexture(t1);
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);
    sprite4.setTexture(t4);
}

SFMLGraphics::SFMLGraphics(SFMLGraphics const &ref) { *this = ref; }
SFMLGraphics::~SFMLGraphics() { window.clear(); window.close(); system("reset"); }

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
    DrawObstacle(snake);
    DrawFruit(fruit);    
    DrawSnake(snake);
    window.display();
}

void SFMLGraphics::DrawObstacle(Snake & snake)
{
    std::vector<std::pair<int, int> > obs;

    obs = snake.getObstacleCoords();

    for (size_t i = 0; i < obs.size(); i++)
    {
        sprite4.setPosition(obs[i].first * size, obs[i].second * size);
        window.draw(sprite4);
    }
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        dr = right;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        dr = down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        dr = up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        dr = stop_the_game;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        dr = change_the_lib;
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