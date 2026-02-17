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

std::vector<sf::Vector2i> Block3D::getAray()
{
    std::vector<sf::Vector2i> geo;
    
    geo.push_back(sf::Vector2i(0,1));
    geo.push_back(sf::Vector2i(2,0));
    geo.push_back(sf::Vector2i(3,1));
    geo.push_back(sf::Vector2i(2,3));

    return geo;
}