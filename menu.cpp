#include "Menu.h"
#include <iostream>

Menu::Menu(float szer, float wys)
{
    if(!font.loadFromFile("comic-sans.ttf"))
    {
    std::cout << "Nie udalo sie zaladowac czcionki";
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Black);
    menu[0].setString("Graj");
    menu[0].setPosition(sf::Vector2f(szer / 2, wys / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Opcje");
    menu[1].setPosition(sf::Vector2f(szer / 2, wys / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Wyjdz");
    menu[2].setPosition(sf::Vector2f(szer / 2, wys / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    wybranyobiekt = 0;

}

Menu::~Menu()
{
    //dtor
}


void Menu::draw(sf::RenderWindow &okienko)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        okienko.draw(menu[i]);
    }
}


void Menu::Gora()
{
    if(wybranyobiekt - 1 >= 0)
    {
        menu[wybranyobiekt].setColor(sf::Color::White);
        wybranyobiekt--;
        menu[wybranyobiekt].setColor(sf::Color::Black);
    }
}

void Menu::Dol()
{
    if(wybranyobiekt + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[wybranyobiekt].setColor(sf::Color::White);
        wybranyobiekt++ ;
        menu[wybranyobiekt].setColor(sf::Color::Black);
    }
}

