#include "block.hpp"

Block::Block(sf::Vector2f n_coo, float l):
    coo(n_coo),
    largeur(l)
{

}

std::vector<sf::Vector2f> Block::getCoo()
{
    std::vector<sf::Vector2f> geo;
    for (int x = 0; x < 3; x++ )
    {
        for (int y = 0; y < 3; y++ )
        {
            geo.push_back(sf::Vector2f(coo.x + x * largeur,coo.y + y * largeur));
        }
    }

    return geo;
}

std::vector<sf::Vector2i> Block::getAray()
{
    std::vector<sf::Vector2i> geo;
    
    for (int i = 0; i < 4; i++ )
    {
        if (i+1 != 4)
        {
            geo.push_back(sf::Vector2i(i,i+1));
        }
        else
        {
            geo.push_back(sf::Vector2i(i,0));
        }
        
    }
    return geo;
}