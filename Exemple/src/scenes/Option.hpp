#ifndef OPTION
#define OPTION

#include "Scene.hpp"
#include "Button.hpp"

class Option : public Scene
{
    private:
        std::string scneneToChange;
        bool wantToChange;

        Button back_button;

    public:
        Option();
        ~Option();
        void event(const sf::Event& event) override;
        void update(float dt) override;
        void draw(sf::RenderWindow& window) override;

        bool wantToChangeScene() override;
        std::string getSceneChangeType() override;
};

#endif