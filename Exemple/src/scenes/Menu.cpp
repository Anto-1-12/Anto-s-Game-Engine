#include "Menu.hpp"

Menu::Menu(): 
    Scene(),
    play_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Play",sf::Color(255,255,255),sf::Color(200,200,200),600,100,70,2.0f),
    option_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Option",sf::Color(255,255,255),sf::Color(200,200,200),600,300.f,70,2.0f)
{
    scneneToChange = "Menu";
    wantToChange = false;
}

void Menu::draw(sf::RenderWindow& window)
{

    play_button.draw(window);
    option_button.draw(window);
}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
    play_button.event(event);
    option_button.event(event);
}

void Menu::update(float dt)
{
    if(play_button.buttonIsClicked())
    {
        
    }
    else if(option_button.buttonIsClicked())
    {

    }
}

bool Menu::wantToChangeScene()
{
    return wantToChange;
}

std::string Menu::getSceneChangeType()
{
    return scneneToChange;
}