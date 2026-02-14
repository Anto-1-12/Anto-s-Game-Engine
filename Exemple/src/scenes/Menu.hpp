#ifndef MENU
#define MENU

#include "Scene.hpp"

class Menu : public Scene
{
    private:
        std::string scneneToChange;
        bool wantToChange;

    public:
        Menu();
        void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
        void update(float dt) override;
        void draw(sf::RenderWindow& window) override;

        bool wantToChangeScene() override;
        std::string getSceneChangeType() override;
};

#endif