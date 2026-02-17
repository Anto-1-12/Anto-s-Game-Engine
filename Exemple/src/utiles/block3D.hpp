#ifndef BLOCK3D
#define BLOCK3D
#include <SFML/Graphics.hpp>
#include<iostream>


class Block3D
{
    private:
        sf::Vector3f coo;
        float largeur;

    public:
        Block3D(sf::Vector3f n_coo, float l);

        std::vector<sf::Vector3f> getCoo();
        std::vector<sf::Vector2i> getAray();

};

#endif