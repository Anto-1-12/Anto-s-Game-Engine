#include "3D.hpp"

D3::D3(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    coo(0,-300,100),
    yawn(0),
    pitch(0),
    vitesse(60)
    //test
{
    //map_obj.push_back(Model3D(sf::Vector3f(100,60,60),"assets/models/model2.obj",0.5));
    map_obj.push_back(Model3D(sf::Vector3f(0,0,0),"assets/models/tourEiffel.obj",100));
    map_obj.push_back(Model3D(sf::Vector3f(60,0,0),"assets/models/block.obj",10));
}

D3::~D3()
{
    
}

void D3::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < map_obj.size() ; i++)
    {
        std::vector<sf::Vector3f> vertexs = map_obj[i].getVertexs();

        std::vector<sf::Vector2f> points;

        for (int a = 0; a < vertexs.size() ; a++)
        {
            //         valeur raw
            //------------------------------------------ 
            sf::Vector3f vertexCoo = vertexs[a];
            
            float w = window.getView().getSize().x;
            float h = window.getView().getSize().y;
            //------------------------------------------ 

            float distance_plan_cam = (w/2)/tan(M_PI/4);

            float odx = vertexCoo.x - coo.x;
            float ody = vertexCoo.y - coo.y;
            float odz = vertexCoo.z - coo.z;

            // ----- YAW -----
            float dx1 = odx * std::cos(yawn) - ody * std::sin(yawn);
            float dy1 = odx * std::sin(yawn) + ody * std::cos(yawn);
            float dz1 = odz;

            // ----- PITCH -----
            float dy2 = dy1 * std::cos(pitch) - dz1 * std::sin(pitch);
            float dz2 = dy1 * std::sin(pitch) + dz1 * std::cos(pitch);
            float dx2 = dx1;

            //verifier si l'objet est devan ou deriere pour ne pas le projetter dans le cas contraire
            if(dy2 > 0)
            {
                float x = (dx2/dy2) * distance_plan_cam + w/2;
                float y = (-dz2/dy2) * distance_plan_cam + h/2;
            
                points.push_back(sf::Vector2f(x, y));
            }
            else
            {
                //pour identifier les points non projeter et garder l'ordre dans la liste de point
                points.push_back(sf::Vector2f(-10000, -10000));
            }
        }

        std::vector<std::vector<int>> faces = map_obj[i].getFaces();

        for ( int b = 0; b < faces.size(); b++)
        {
            sf::ConvexShape triangle;
            triangle.setPointCount(faces[b].size());

            bool draw = true;

            for ( int  p = 0; p < faces[b].size(); p++)
            {
                if (points[faces[b][p]] == sf::Vector2f(-10000, -10000))
                {
                    draw = false;
                }
                triangle.setPoint(p, points[faces[b][p]]);
            }

            if(draw)
            {
                window.draw(triangle);
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
        coo.x += forwardX * vitesse * dt;
        coo.y += forwardY * vitesse * dt;
    }

    // RECULER
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        coo.x -= forwardX * vitesse * dt;
        coo.y -= forwardY * vitesse * dt;
    }

    // GAUCHE (strafe)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        coo.x -= rightX * vitesse * dt;
        coo.y -= rightY * vitesse * dt;
    }

    // DROITE (strafe)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        coo.x += rightX * vitesse * dt;
        coo.y += rightY * vitesse * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        coo.z += vitesse * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
    {
        coo.z -= vitesse * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        yawn -= (vitesse*2)/40 * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        yawn += (vitesse*2)/40 * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        pitch -= (vitesse*2)/40 * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        pitch += (vitesse*2)/40 * dt;
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