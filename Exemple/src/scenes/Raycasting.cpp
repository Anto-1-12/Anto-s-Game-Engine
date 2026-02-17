#include "Raycasting.hpp"

Raycasting::Raycasting(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    coo(15,15),
    angle(0)
    //test
{
    map.push_back(Block(sf::Vector2f(0,0),10));
}

Raycasting::~Raycasting()
{
    
}

void Raycasting::draw(sf::RenderWindow& window)
{

    for (int i = 0; i < map.size() ; i++)
    {
        std::vector<sf::Vector2f> block = map[i].getCoo();
        for (int i = 0; i < block.size() ; i++)
        {
            sf::Vector2f blockCoo = block[i];
            
            float w = window.getView().getSize().x;
            float h = window.getView().getSize().y;

            

        }
    }

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
