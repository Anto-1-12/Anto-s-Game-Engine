#ifndef RAYCASTING
#define RAYCASTING
#include "Scene.hpp"
#include "Button.hpp"
#include "block.hpp"

class Raycasting : public Scene
{
    private:

        std::string scneneToChange;
        bool wantToChange;

        Button menu_button;

        std::vector<Block> map;
        sf::Vector2f coo;
        float angle;

    public:
        Raycasting();
        ~Raycasting();
        void event(const sf::Event& even) override;
        void update(float dt) override;
        void draw(sf::RenderWindow& window) override;

        bool wantToChangeScene() override;
        std::string getSceneChangeType() override;
};


#endif