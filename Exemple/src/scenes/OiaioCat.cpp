#include "OiaioCat.hpp"

OiaioCat::OiaioCat(): 
    Scene(),
    menu_button("assets/textures/Button.png","assets/textures/Button2.png","assets/fonts/Runtti-Regular.ttf","Menu",sf::Color(255,255,255),sf::Color(200,200,200),170,70,70,2.0f),
    scneneToChange("Menu"),
    wantToChange(false),
    coo(0,-100,20),
    yawn(0),
    pitch(0),
    vitesse(60),
    back_ground_color(0,0,0),
    color(0),
    rotation(0)
    //test
{
    map_obj.push_back(Model3D(sf::Vector3f(0,0,0),"assets/models/OiiaioooooiaiFin.obj",1));
    map_obj[0].set_show(true);
    map_obj.push_back(Model3D(sf::Vector3f(0,0,0),"assets/models/cat1.obj",100));
    map_obj[1].set_show(false);
}

OiaioCat::~OiaioCat()
{
    
}

void OiaioCat::draw(sf::RenderWindow& window)
{

    window.clear(back_ground_color);

    for (int i = 0; i < map_obj.size() ; i++)
    {
        if (map_obj[i].get_show()){
            std::vector<sf::Vector3f> vertexs = map_obj[i].getVertexs();

            std::vector<sf::Vector2f> points;

            map_obj[i].turn_model(sf::Vector3f(rotation,0,0));

            for (int a = 0; a < vertexs.size() ; a++)
            {
                sf::Vector3f xyz = turn_point(coo,vertexs[a],sf::Vector3f(yawn,pitch,0));

                //verifier si l'objet est devan ou deriere pour ne pas le projetter dans le cas contraire
                if(xyz.y > 0)
                {
                    points.push_back(projection(xyz,window.getView().getSize(),M_PI/2));
                }
                else
                {
                    //pour identifier les points non projeter et garder l'ordre dans la liste de point
                    points.push_back(sf::Vector2f(-10000, -10000));
                }
            }

            std::vector<std::vector<int>> faces = map_obj[i].getFaces();
            std::vector<sf::Vector3f> vns = map_obj[i].getVectorNormal();

            for ( int b = 0; b < faces.size(); b++)
            {
                sf::Vector3f vn = vns[b];
                sf::Vector3f vd = vn - coo;

                float dot_prod = vn.x*vd.x + vn.y*vd.y + vn.z*vd.z;

                if(dot_prod <= 0)
                {
                    sf::ConvexShape triangle;
                    triangle.setPointCount(faces[b].size());

                    if (dot_prod < -255*2)
                    {
                        dot_prod = -255 * 2;
                    }

                    triangle.setFillColor(sf::Color(dot_prod * 0.5,dot_prod * 0.5,dot_prod * 0.5));
                

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
        }
    }

    menu_button.draw(window);
}

void OiaioCat::event(const sf::Event& event)
{
    menu_button.event(event);
}

void OiaioCat::update(float dt)
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

    color += 10 * dt;
    rotation -= dt * 30;

    if (color > 25500)
    {
        color -= 25500;
    }

    back_ground_color = sf::Color(color*1.3,color*32,color*87);

}

bool OiaioCat::wantToChangeScene()
{
    return wantToChange;
}

std::string OiaioCat::getSceneChangeType()
{
    return scneneToChange;
}