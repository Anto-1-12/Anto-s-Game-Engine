#include "block3D.hpp"

Block3D::Block3D(sf::Vector3f n_coo, float l):
    coo(n_coo),
    largeur(l)
{

}

std::vector<sf::Vector3f> Block3D::getCoo()
{
    std::vector<sf::Vector3f> geo;
    for (int x = 0; x < 2; x++ )
    {
        for (int y = 0; y < 2; y++ )
        {
            for (int z = 0; z < 2; z++ )
            {
                geo.push_back(sf::Vector3f(coo.x + x * largeur,coo.y + y * largeur,coo.z + z * largeur));
            }
        }
    }

    return geo;
}

std::vector<std::vector<int>> Block3D::getAray()
{
    std::vector<std::vector<int>> geo;
    
    std::vector<int> face_1;
    face_1.push_back(0);
    face_1.push_back(1);
    face_1.push_back(5);
    face_1.push_back(4);
    geo.push_back(face_1);

    std::vector<int> face_2;
    face_2.push_back(4);
    face_2.push_back(5);
    face_2.push_back(7);
    face_2.push_back(6);
    geo.push_back(face_2);
    
    std::vector<int> face_3;
    face_3.push_back(6);
    face_3.push_back(2);
    face_3.push_back(3);
    face_3.push_back(7);
    geo.push_back(face_3);

    std::vector<int> face_4;
    face_4.push_back(3);
    face_4.push_back(2);
    face_4.push_back(0);
    face_4.push_back(1);
    geo.push_back(face_4);

    std::vector<int> face_5;
    face_5.push_back(6);
    face_5.push_back(4);
    face_5.push_back(0);
    face_5.push_back(2);
    geo.push_back(face_5);

    std::vector<int> face_6;
    face_6.push_back(1);
    face_6.push_back(3);
    face_6.push_back(7);
    face_6.push_back(5);
    geo.push_back(face_6);

    return geo;
}