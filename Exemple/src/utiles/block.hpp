#ifndef BLOCK
#define BLOCK
#include <SFML/Graphics.hpp>
#include<iostream>


class Block
{
    private:
        sf::Vector2f coo;
        float largeur;

    public:
        Block(sf::Vector2f n_coo, float l);

        std::vector<sf::Vector2f> getCoo();
        std::vector<sf::Vector2i> getAray();

};

#endif