#include "Menu.hpp"

Menu::Menu(): Scene()
{
    scneneToChange = "Menu";
    wantToChange = false;
}

void Menu::draw(sf::RenderWindow& window)
{

}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{

}

void Menu::update(float dt)
{

}

bool Menu::wantToChangeScene()
{
    return wantToChange;
}

std::string Menu::getSceneChangeType()
{
    return scneneToChange;
}