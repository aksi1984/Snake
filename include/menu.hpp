#ifndef MENU_HPP
#define MENU_HPP

#include "state.hpp"
#include "menutext.hpp"
#include "myUtility.hpp"

class Menu : public State
{
public:
    Menu();

    virtual void run(sf::RenderWindow& window);

private:
    void checkTheTextSelect(sf::RenderWindow& window);
    void checkButtonClicked();

    MenuText menuText;
};

#endif // MENU_HPP
