#ifndef MENU_H
#define MENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    public:
        Menu(float szer, float wys);
        virtual ~Menu();

        void draw(sf::RenderWindow &okienko);
        void Gora();
        void Dol();
        int pobierzinfo() { return wybranyobiekt; }

    private:
        int wybranyobiekt;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // MENU_H
