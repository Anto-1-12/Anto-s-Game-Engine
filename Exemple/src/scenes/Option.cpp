 #include "Option.hpp"

 Option::Option(): 
    Scene(),
    back_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Back",sf::Color(255,255,255),sf::Color(200,200,200),600,200,70,2.0f)
{
    scneneToChange = "Menu";
    wantToChange = false;
}

Option::~Option()
{
    
}

void Option::draw(sf::RenderWindow& window)
{
    back_button.draw(window);
}

void Option::event(const sf::Event& event)
{
    back_button.event(event);
    
    //gestion de la resize
    //pas necessaire si on utilise un view
    /*
    if (const auto* resized = event.getIf<sf::Event::Resized>())
    {
        sf::Vector2f size_back_b = back_button.get_size();
        
        float coeff_x = static_cast<float>(resized->size.x)/1600.f;
        float coeff_y = static_cast<float>(resized->size.y)/900.f;

        back_button.resize(sf::Vector2f(size_back_b.x*coeff_x,size_back_b.y*coeff_y));
        
    }
    */
}

void Option::update(float dt)
{
    if(back_button.buttonIsClicked())
    {
        scneneToChange = "Menu";
        wantToChange = true;
    }
}

bool Option::wantToChangeScene()
{
    return wantToChange;
}

std::string Option::getSceneChangeType()
{
    return scneneToChange;
}