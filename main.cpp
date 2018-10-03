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

                if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
                {
                okienko.close();
                }
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

                        bool sync =true;
                        sf::RenderWindow okienkog(sf::VideoMode(800, 600), "Gra");
                        okienkog.setFramerateLimit(80);
                        okienkog.setVerticalSyncEnabled(sync);
                        sf::CircleShape circle;
                        float predkoscl = 10,predkoscp = 10, predkoscg = 10, predkoscd = 10;
                        circle.setRadius(20);
                        circle.setOutlineColor(sf::Color::Magenta);
                        circle.setOutlineThickness(5);
                        float x = 380, y = 280;
                        circle.setFillColor(sf::Color::Cyan);
                        sf::RectangleShape kwadrat( sf::Vector2f( 100, 100 ) );
                        kwadrat.setPosition( 200, 100 );
                        kwadrat.setFillColor(sf::Color::Red);

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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x >= 15)
                    x-=predkoscl;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x <= 745)
                    x+=predkoscp;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y >= 15)
                    y-=predkoscg;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y <= 545)
                    y+=predkoscd;

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && circle.getGlobalBounds().intersects(kwadrat.getGlobalBounds()))
             {
                std::cout << "rozbiles sie \n";
                predkoscl*=0;
             }
             else {predkoscl = 10;}

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && circle.getGlobalBounds().intersects(kwadrat.getGlobalBounds()))          //KOD NA Kolizje w trakcie pracy
             {
                std::cout << "rozbiles sie \n";
                predkoscp*=0;
             }
             else {predkoscp = 10;}

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && circle.getGlobalBounds().intersects(kwadrat.getGlobalBounds()))
             {
                std::cout << "rozbiles sie \n";
                predkoscg*=0;
             }
             else{predkoscg = 10;}

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circle.getGlobalBounds().intersects(kwadrat.getGlobalBounds()))
             {
                std::cout << "rozbiles sie \n";
                predkoscd*=0;
             }
             else {predkoscd = 10;}

            }

            circle.setPosition(x, y);
            okienkog.clear();
            okienkog.draw(circle);
            okienkog.draw(kwadrat);
            menu.obiekt(okienkog);
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

        menu.wstaw(okienko);

        okienko.display();
    }

    return 0;
}
