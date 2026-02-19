#include "model3D.hpp"

Model3D::Model3D(sf::Vector3f n_coo,std::string geo,float coeff_size):
    coo(n_coo),
    file(geo),
    size(coeff_size)
{
    std::ifstream goe_file(file);

    std::string line;

    std::vector<std::vector<int>> vectorNormalIndex;

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
        if (type == "vn")
        {
            //def points
            sf::Vector3f vectorNormal;
            ss >> vectorNormal.x >> vectorNormal.z >> vectorNormal.y;
            vn.push_back(vectorNormal);
        }
        if (type == "f")
        {
            //def faces

            std::vector<int> index_vertex;

            std::vector<int> v_i;

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
                v_i.push_back(std::stoi(indexStr) - 1);

            }

            vectorNormalIndex.push_back(v_i);

            faces.push_back(index_vertex);
        }
    
    }

    for (int z = 0; z < vectorNormalIndex.size(); z++)
    {
        
        sf::Vector3f v;

        for (int y = 0; y < vectorNormalIndex[z].size(); y++)
        {
            v += vn[vectorNormalIndex[z][y]];
        }

        float no = std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

        v = v/no;

        vn_by_face.push_back(v);
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

std::vector<sf::Vector3f> Model3D::getVectorNormal()
{
    return vn_by_face;
}