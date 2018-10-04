#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include <math.h>

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
                        float predkosclp = 5.0, predkoscgd = 5.0;
                        circle.setRadius(20);
                        sf::Vector2f postac;
                        postac.x = 380;
                        postac.y = 280;
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

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && postac.x >= 15)
                    postac.x-=predkosclp;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && postac.x <= 745)
                    postac.x+=predkosclp;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && postac.y >= 15)
                    postac.y-=predkoscgd;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && postac.y <= 545)
                    postac.y+=predkoscgd;

                    sf::FloatRect rectToMove(postac, {circle.getGlobalBounds().width, circle.getGlobalBounds().width});

                    if(rectToMove.intersects(kwadrat.getGlobalBounds()))
                {

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && postac.x < kwadrat.getPosition().x + kwadrat.getGlobalBounds().width)
             {
                postac.x=kwadrat.getPosition().x + kwadrat.getGlobalBounds().width;
             }

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && postac.x > kwadrat.getPosition().x - kwadrat.getGlobalBounds().width)   //Kolizja prawie dziala!
             {
                postac.x=kwadrat.getPosition().x - circle.getGlobalBounds().width;
             }

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && postac.y > kwadrat.getPosition().y - kwadrat.getGlobalBounds().height)
             {
                postac.y=kwadrat.getPosition().y - circle.getGlobalBounds().height;
             }

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && postac.y < kwadrat.getPosition().y + kwadrat.getGlobalBounds().height)
             {
                postac.y=kwadrat.getPosition().y + kwadrat.getGlobalBounds().height;
             }
                }


            }

            circle.setPosition(postac);
            okienkog.clear();
            okienkog.draw(circle);
            okienkog.draw(kwadrat);
            //menu.obiekt(okienkog);
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
