#ifndef MENU_HPP
#define MENU_HPP

#include "menutext.hpp"
#include "myUtility.hpp"

class Menu
{
public:
    Menu();

    void run(sf::RenderWindow& window);
    MenuState getMenuState() const;

private:
    void checkTheTextSelect(sf::RenderWindow& window);
    void checkButtonClicked();

    MenuText menuText;
    MenuState menuState;
};

#endif // MENU_HPP
