#include "Raycasting.hpp"

Raycasting::Raycasting(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false)
{
}

Raycasting::~Raycasting()
{
    
}

void Raycasting::draw(sf::RenderWindow& window)
{
    menu_button.draw(window);
}

void Raycasting::event(const sf::Event& event)
{
    menu_button.event(event);
}

void Raycasting::update(float dt)
{
    if(menu_button.buttonIsClicked())
    {
        scneneToChange = "Menu";
        wantToChange = true;
    }
}

bool Raycasting::wantToChangeScene()
{
    return wantToChange;
}

std::string Raycasting::getSceneChangeType()
{
    return scneneToChange;
}
