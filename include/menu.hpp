#ifndef MENU_HPP
#define MENU_HPP

#include "menutext.hpp"

class Menu
{
public:
    Menu();

    void run(sf::RenderWindow& window);

private:
    void checkTheTextSelect(sf::RenderWindow& window);

    MenuText menuText;
};

#endif // MENU_HPP
