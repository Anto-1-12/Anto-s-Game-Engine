#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "SceneType.hpp"
#include "Menu.hpp"

class Game
{
private:
    //variables
    sf::RenderWindow window;
    sf::View view;
    sf::Clock clock;

    bool isFullScreen = false;

    // le scene manager
    SceneManager sceneManager;

    float dt;

public:
    //methode lancement de la boucle
    void run();

    //constructeur
    Game();

    // destructeur ~Game();
};

#endif