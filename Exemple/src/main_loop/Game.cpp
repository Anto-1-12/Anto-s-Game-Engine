#include "Game.hpp"

//initialisation des variables
Game::Game(): 
    //fenetre
    window(sf::VideoMode({1280, 720}), "Exemple", sf::Style::Titlebar | sf::Style::Close),
    //vue de la fenetre
    view(sf::FloatRect({0.0f, 0.0f}, {1600.0f, 900.0f})),
    //initialiser le SceneManager
    sceneManager(new Menu(),new SceneType()),
    //le delta time pour les corrections de déplacement
    dt(1.0f / 60.0f)
{
    window.setView(view);
}

//La methode run
void Game::run()
{
    float accumulator = 0.0f;

    //tant que la fenetre est ouverte
    while (window.isOpen())
    {

        //               Events SFML
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }
            
            //           Events SceneManager
            //------------------------------------------------
            if (event.has_value())
            {
                sceneManager.handelEvent(event.value(),window);
            }
            //------------------------------------------------

        }
        
        //temps entre deux tour de boucle
        float frameTime = clock.restart().asSeconds();
        //on ajoute le temps écoulé a l'accumulateur
        accumulator += frameTime;

        //             update le SceneManager
        //---------------------------------------------
        while (accumulator >= dt) 
        {
            
            sceneManager.update(dt);
            // reinitialisation de l'accumulateur
            accumulator -= dt;
        }
        
        //               Zone de dessin
        //---------------------------------------------
        window.clear();
        
        //dessin de la scene
        sceneManager.draw(window);

        window.display();
        //---------------------------------------------
    }
}