#include "game.hpp"
#include "menu.hpp"

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "Test");

    Menu menu;

    while(app.isOpen())
    {
        sf::Event e;

        while(app.pollEvent(e))
        {
            if(e.type == sf::Event::Closed || menu.getState() == GameState::Exit)
                app.close();
        }

        app.clear(sf::Color::White);
        menu.run(app);
        app.display();
    }

    //Game g;
    //g.run();

    return 0;
}
