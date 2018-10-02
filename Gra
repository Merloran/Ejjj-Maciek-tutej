#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

int main()
{
    menu:
    sf::RenderWindow okienko(sf::VideoMode(600, 600), "MENU");

    Menu menu(okienko.getSize().x, okienko.getSize().y);

    while (okienko.isOpen())
    {
        sf::Event zdarzenie;
        while (okienko.pollEvent(zdarzenie))
        {
            switch(zdarzenie.type)
            {
            case sf::Event::KeyReleased:
                switch (zdarzenie.key.code)
                {
                case sf::Keyboard::Up:
                    menu.Gora();
                    break;

                case sf::Keyboard::Down:
                    menu.Dol();
                    break;

                case sf::Keyboard::Return:

                    if(menu.pobierzinfo() == 0)
                    {
                        okienko.close();

                        sf::RenderWindow okienkog(sf::VideoMode(800, 600), "Gra");
                        sf::CircleShape circle;
                        circle.setRadius(20);
                        circle.setOutlineColor(sf::Color::Red);
                        circle.setOutlineThickness(5);
                        float x = 380, y = 280;
                        circle.setFillColor(sf::Color::Green);

                while (okienkog.isOpen())
        {
            sf::Event zdarzenieg;
            while (okienkog.pollEvent(zdarzenieg))
            {
                if (zdarzenieg.type == sf::Event::Closed)
                okienkog.close();
                if(zdarzenieg.type == sf::Event::KeyPressed && zdarzenieg.key.code == sf::Keyboard::Escape)
                {
                goto menu;
                }
                if(zdarzenieg.type == sf::Event::KeyPressed && zdarzenieg.key.code == sf::Keyboard::Left)
                    x-=10;
                if(zdarzenieg.type == sf::Event::KeyPressed && zdarzenieg.key.code == sf::Keyboard::Right)
                    x+=10;
                if(zdarzenieg.type == sf::Event::KeyPressed && zdarzenieg.key.code == sf::Keyboard::Up)
                    y-=10;
                if(zdarzenieg.type == sf::Event::KeyPressed && zdarzenieg.key.code == sf::Keyboard::Down)
                    y+=10;
            }
            circle.setPosition(x, y);
            okienkog.clear();
            okienkog.draw(circle);
            okienkog.display();

        }
                    }

                    switch (menu.pobierzinfo())
                    {
                    case 1:
                        std::cout << "Wcisnieto przycisk opcje \n";
                        break;
                    case 2:
                        okienko.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::Closed:
                okienko.close();

                break;
            }
        }

        okienko.clear(sf::Color::Blue);

        menu.draw(okienko);

        okienko.display();
    }

    return 0;
}
