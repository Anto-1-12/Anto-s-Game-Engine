#ifndef BUTTON
#define BUTTON
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
private:

    sf::Font font;
    sf::Text text;
    
    float coo_x;
    float coo_y;

    float buttonBorder;
    
    sf::FloatRect hitBox;
    sf::Texture bg;
    sf::Texture bgMouse;
    
    sf::Sprite backGround;

    sf::Color textColor;
    sf::Color mouseOnTextColor;

    bool mouseIsOnItSelf = false;
    bool isClicked = false;

    bool checkMouse(sf::RenderWindow& window);

public:
    Button(std::string backTexture,std::string mouseBackTexture,std::string police,std::string txt,sf::Color color,sf::Color mouseOnColor, float x,float y,int textScale,float borderSize);
    ~Button();
    void draw(sf::RenderWindow& window);
    void event(const sf::Event& event);
    void setCoo(float x,float y);

    bool buttonIsClicked();
};

#endif