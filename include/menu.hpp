#ifndef MENU_HPP
#define MENU_HPP

#include "state.hpp"
#include "menutext.hpp"
#include "myUtility.hpp"

class Menu : public State
{
public:
    Menu();

    void run(sf::RenderWindow& window);

private:
    void processEvent(sf::RenderWindow& window);
    void checkTheTextSelect(sf::RenderWindow& window);
    void checkButtonClicked();
    void render(sf::RenderWindow& window);

    MenuText menuText;
};

#endif // MENU_HPP
