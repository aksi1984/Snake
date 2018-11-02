#include "menu.hpp"

Menu::Menu() { }

void Menu::run(sf::RenderWindow& window)
{
    processEvent(window);
    checkTheTextSelect(window);
    checkButtonClicked();
    render(window);
}

void Menu::processEvent(sf::RenderWindow& window)
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed || State::getState() == GameStates::Exit)
            window.close();
    }
}

void Menu::checkTheTextSelect(sf::RenderWindow& window)
{
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

    for(std::size_t i = 0; i < menuText.getSize(); ++i)
    {
        if(menuText.getGlobalBounds(i).contains(mousePosition))
        {
            menuText.changeColor(i, sf::Color::Red);
        }
        else
            menuText.changeColor(i, sf::Color::Blue);
    }
}

void Menu::checkButtonClicked()
{
    for(std::size_t i = 0; i < menuText.getSize(); ++i)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && menuText.getColor(i) == sf::Color::Red)
        {
            menuText.changeColor(i, sf::Color::Magenta);

            State::setState( (i == 0 ? GameStates::StateGame : GameStates::Exit) );
        }
    }
}

void Menu::render(sf::RenderWindow& window)
{
    menuText.draw(window);
}


