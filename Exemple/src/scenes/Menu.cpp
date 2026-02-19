#include "Menu.hpp"

Menu::Menu(): 
    Scene(),
    play_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Play",sf::Color(255,255,255),sf::Color(200,200,200),800,150,70,2.0f),
    option_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Option",sf::Color(255,255,255),sf::Color(200,200,200),800,350.f,70,2.0f),
    raycasting_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Raycasting",sf::Color(255,255,255),sf::Color(200,200,200),800,550.f,70,2.0f),
    D3_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","3D",sf::Color(255,255,255),sf::Color(200,200,200),800,750.f,70,2.0f),
    oiaio_cat_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Oiaio Cat",sf::Color(255,255,255),sf::Color(200,200,200),300,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    bg("assets/textures/bground.png"),
    backGround(bg)
{
    sf::Vector2f size = sf::Vector2f(bg.getSize().x,bg.getSize().y);
    backGround.setScale({1600/size.x,900/size.y});
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{

    //      faire un background pas affecté par le letterboxing
    //---------------------------------------------------------------
    sf::View actualView = window.getView();

    window.setView(window.getDefaultView());

    sf::Vector2f size = sf::Vector2f(backGround.getTexture().getSize().x,backGround.getTexture().getSize().y);
    sf::Vector2f windowSize = sf::Vector2f(static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y));
    
    backGround.setScale({windowSize.x/size.x,windowSize.y/size.y});

    window.draw(backGround);

    window.setView(actualView);
    //---------------------------------------------------------------
    
    play_button.draw(window);
    option_button.draw(window);
    raycasting_button.draw(window);
    D3_button.draw(window);
    oiaio_cat_button.draw(window);
}

void Menu::event(const sf::Event& event)
{
    play_button.event(event);
    option_button.event(event);
    raycasting_button.event(event);
    D3_button.event(event);
    oiaio_cat_button.event(event);

    //gestion de la resize
    
    /*
    if (const auto* resized = event.getIf<sf::Event::Resized>())
    {
        //pas necessaire si on utilise un view
        
        sf::Vector2f size_play_b = play_button.get_size();
        sf::Vector2f size_option_b = option_button.get_size();
        
        float coeff_x = static_cast<float>(resized->size.x)/1600.f;
        float coeff_y = static_cast<float>(resized->size.y)/900.f;

        play_button.resize(sf::Vector2f(size_play_b.x*coeff_x,size_play_b.y*coeff_y));
        option_button.resize(sf::Vector2f(size_option_b.x*coeff_x,size_option_b.y*coeff_y));
        
    }
    */
}

void Menu::update(float dt)
{
    if(play_button.buttonIsClicked())
    {
        
    }
    else if(option_button.buttonIsClicked())
    {
        scneneToChange = "Option";
        wantToChange = true;
    }
    else if(raycasting_button.buttonIsClicked())
    {
        scneneToChange = "Raycasting";
        wantToChange = true;
    }
    else if(D3_button.buttonIsClicked())
    {
        scneneToChange = "3D";
        wantToChange = true;
    }
    else if(oiaio_cat_button.buttonIsClicked())
    {
        scneneToChange = "OIAIOCAT";
        wantToChange = true;
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