#ifndef MODEL3D
#define MODEL3D
#include <SFML/Graphics.hpp>
#include<iostream>

#include <sstream>
#include <fstream>


class Model3D
{
    private:
        sf::Vector3f coo;
        std::string file;
        std::vector<sf::Vector3f> points;
        std::vector<std::vector<int>> faces;

        float size;

    public:
        Model3D(sf::Vector3f n_coo,std::string geo, float coeff_size);

        std::vector<sf::Vector3f> getVertexs();
        std::vector<std::vector<int>> getFaces();

};

#endif