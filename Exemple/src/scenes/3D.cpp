#include "3D.hpp"

D3::D3(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    coo(30,30,0),
    yawn(2.05),
    pitch(0),
    vitesse(1)
    //test
{
    map.push_back(Block3D(sf::Vector3f(0,60,-10),20));
    map.push_back(Block3D(sf::Vector3f(60,0,-10),20));
    map.push_back(Block3D(sf::Vector3f(0,0,-10),20));
    map.push_back(Block3D(sf::Vector3f(60,60,-10),20));
}

D3::~D3()
{
    
}

void D3::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < map.size() ; i++)
    {
        std::vector<sf::Vector3f> block = map[i].getCoo();

        std::vector<sf::Vector2f> points;

        for (int a = 0; a < block.size() ; a++)
        {
            //         valeur raw
            //------------------------------------------ 
            sf::Vector3f blockCoo = block[a];
            
            float w = window.getView().getSize().x;
            float h = window.getView().getSize().y;
            //------------------------------------------ 

            float distance_plan_cam = (w/2)/tan(M_PI/4);

            float odx = blockCoo.x - coo.x;
            float ody = blockCoo.y - coo.y;
            float odz = blockCoo.z - coo.z;

            // ----- YAW -----
            float dx1 = odx * std::cos(yawn) - ody * std::sin(yawn);
            float dy1 = odx * std::sin(yawn) + ody * std::cos(yawn);
            float dz1 = odz;

            // ----- PITCH -----
            float dy2 = dy1 * std::cos(pitch) - dz1 * std::sin(pitch);
            float dz2 = dy1 * std::sin(pitch) + dz1 * std::cos(pitch);
            float dx2 = dx1;

            if(dy2 > 0)
            {
                float x = (dx2/dy2) * distance_plan_cam + w/2;
                float y = (-dz2/dy2) * distance_plan_cam + h/2;
            
                points.push_back(sf::Vector2f(x, y));
            }
            else
            {
                points.push_back(sf::Vector2f(-10000, -10000));
            }
        }

        std::vector<std::vector<int>> geo = map[i].getAray();

        for ( int b = 0; b < geo.size(); b++)
        {

            sf::Vector2f A = points[geo[b][0]];
            sf::Vector2f B = points[geo[b][1]];
            sf::Vector2f C = points[geo[b][2]];
            sf::Vector2f D = points[geo[b][3]];

            if (!(A == sf::Vector2f(-10000, -10000) || B == sf::Vector2f(-10000, -10000) || C == sf::Vector2f(-10000, -10000) || D == sf::Vector2f(-10000, -10000)))
            {
                sf::ConvexShape carre;
                carre.setPointCount(4);
            
                carre.setPoint(0, A);
                carre.setPoint(1, B);
                carre.setPoint(2, C);
                carre.setPoint(3, D);

                window.draw(carre);
            }
        }
    }

    menu_button.draw(window);
}

void D3::event(const sf::Event& event)
{
    menu_button.event(event);
}

void D3::update(float dt)
{
    float forwardX = std::sin(yawn);
    float forwardY = std::cos(yawn);

    float rightX = std::cos(yawn);
    float rightY = -std::sin(yawn);

    if(menu_button.buttonIsClicked())
    {
        scneneToChange = "Menu";
        wantToChange = true;
    }

    // AVANCER
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
        coo.x += forwardX * vitesse;
        coo.y += forwardY * vitesse;
    }

    // RECULER
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        coo.x -= forwardX * vitesse;
        coo.y -= forwardY * vitesse;
    }

    // GAUCHE (strafe)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        coo.x -= rightX * vitesse;
        coo.y -= rightY * vitesse;
    }

    // DROITE (strafe)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        coo.x += rightX * vitesse;
        coo.y += rightY * vitesse;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        coo.z += vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
    {
        coo.z -= vitesse;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        yawn -= (vitesse*2)/30;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        yawn += (vitesse*2)/30;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        pitch -= (vitesse*2)/30;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        pitch += (vitesse*2)/30;
    }

}

bool D3::wantToChangeScene()
{
    return wantToChange;
}

std::string D3::getSceneChangeType()
{
    return scneneToChange;
}