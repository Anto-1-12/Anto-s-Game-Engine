#include "model3D.hpp"

Model3D::Model3D(sf::Vector3f n_coo,std::string geo,float coeff_size):
    coo(n_coo),
    file(geo),
    size(coeff_size)
{
    std::ifstream goe_file(file);

    std::string line;

    while(std::getline(goe_file, line))
    {   
        
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v")
        {
            //def points
            sf::Vector3f v;
            ss >> v.x >> v.z >> v.y;
            points.push_back(v);
        }
        if (type == "f")
        {
            //def faces

            std::vector<int> index_vertex;

            std::string vert;
            while (ss >> vert)
            {
                std::stringstream vs(vert);
                std::string indexStr;

                //vertex index
                std::getline(vs, indexStr, '/');
                index_vertex.push_back(std::stoi(indexStr) - 1);

                //texture index
                std::getline(vs, indexStr, '/');

                //normal index
                std::getline(vs, indexStr, '/');

            }

            faces.push_back(index_vertex);
        }
    
    }

    std::vector<sf::Vector3f> vertex_in_space;

    for (int i = 0; i < points.size(); i++)
    {
        vertex_in_space.push_back((points[i]*size)+coo);
    }

    points = vertex_in_space;

}

std::vector<sf::Vector3f> Model3D::getVertexs()
{
    return points;
}

std::vector<std::vector<int>> Model3D::getFaces()
{
    return faces;
}