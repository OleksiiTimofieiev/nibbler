#include "/Users/hdanylev/.brew/Cellar/sfml/2.4.2_1/include/SFML/Graphics.hpp"

int main()
{
    // создаём окно
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Hello World - SFML");

    // основной цикл
    while (app.isOpen())
    {
        // проверяем события (нажатие кнопки, закрытие окна и т.д.)
        sf::Event event;
        while (app.pollEvent(event))
        {
            // если событие "закрытие окна":
            if (event.type == sf::Event::Closed)
                 // закрываем окно 
                app.close();
        }

        // очищаем экран и заливаем его синим цветом
        app.clear(sf::Color(230,230,250));

        // отображаем на экран
        app.display();
    }

    return 0;
}
