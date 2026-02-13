#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>

class Game
{
private:
    //variables
    sf::RenderWindow window;
    sf::View view;
    sf::Clock clock;

    float dt;

public:
    //methode lancement de la boucle
    void run();

    //constructeur
    Game();

    // destructeur ~Game();
};

#endif