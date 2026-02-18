#include "Raycasting.hpp"

Raycasting::Raycasting(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    coo(30,30),
    angle(2.05),
    vitesse(60)
    //test
{
    map.push_back(Block(sf::Vector2f(0,0),20));
    map.push_back(Block(sf::Vector2f(0,60),20));
    map.push_back(Block(sf::Vector2f(60,0),20));
    map.push_back(Block(sf::Vector2f(60,60),20));
}

Raycasting::~Raycasting()
{
    
}

void Raycasting::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < map.size() ; i++)
    {
        std::vector<sf::Vector2f> block = map[i].getCoo();

        std::vector<std::vector<sf::Vector2f>> points;

        for (int a = 0; a < block.size() ; a++)
        {
            //         valeur raw
            //------------------------------------------ 
            sf::Vector2f blockCoo = block[a];
            
            float w = window.getView().getSize().x;
            float h = window.getView().getSize().y;
            //------------------------------------------ 

            float dx = blockCoo.x - coo.x;
            float dy = blockCoo.y - coo.y;

            float ray_size = sqrt(dx * dx + dy * dy);

            float angle_ray = std::fmod(std::atan2(dy, dx), 2.0 * M_PI);
            
            float reel_angle = angle_ray - angle;
            float reel_ray_size = std::cos(reel_angle) * ray_size;
            float height_wall = (h * 10)/(reel_ray_size + 0.0001);
            
            float distance_du_centre = (std::tan(reel_angle)/std::tan(M_PI/4))*(w/2)+w/2;

            std::vector<sf::Vector2f> point;
            
            point.push_back(sf::Vector2f(distance_du_centre, h/2 + height_wall));
            point.push_back(sf::Vector2f(distance_du_centre, h/2 - height_wall)); 

            if (reel_angle > M_PI)  reel_angle -= 2*M_PI;
            if (reel_angle < -M_PI) reel_angle += 2*M_PI;

            if (std::abs(reel_angle) < M_PI/4)
            {
                points.push_back(point);
            }
        }

        std::vector<sf::Vector2i> aretes = map[i].getAray();

        for (int b = 0; b < aretes.size(); b++)
        {
            if (!points.empty()){
                if (points.size() > aretes[b].x && points.size() > aretes[b].y)
                {
                    sf::ConvexShape carre;
                    carre.setPointCount(4);
            
                    carre.setPoint(0, points[aretes[b].x][0]);
                    carre.setPoint(1, points[aretes[b].x][1]);
                    carre.setPoint(3, points[aretes[b].y][0]);
                    carre.setPoint(2, points[aretes[b].y][1]);

                    window.draw(carre);
                }
            }
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
        coo.x += std::cos(angle) * vitesse * dt;
        coo.y += std::sin(angle) * vitesse * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        coo.x -= std::cos(angle) * vitesse * dt;
        coo.y -= std::sin(angle) * vitesse * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        coo.x -= std::cos(angle + M_PI/2) * vitesse * dt;
        coo.y -= std::sin(angle + M_PI/2) * vitesse * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        coo.x += std::cos(angle + M_PI/2) * vitesse * dt;
        coo.y += std::sin(angle + M_PI/2) * vitesse * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        angle -= (vitesse*2)/30 * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        angle += (vitesse*2)/30 * dt;
        
    }
    
    if (angle < 0)
    {    
        angle += M_PI * 2;
    }
    else if (angle > M_PI * 2)
    {
        angle -= M_PI * 2;
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
