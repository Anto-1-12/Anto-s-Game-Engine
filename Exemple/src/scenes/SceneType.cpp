#include "SceneType.hpp"
#include "Menu.hpp"
#include "Option.hpp"
#include "Raycasting.hpp"
#include "3D.hpp"

//constructeur
SceneType::SceneType()
{

}

//destructeur
SceneType::~SceneType()
{

}

Scene* SceneType::getSceneFromType(std::string type)
{
    //on defini les types de scenes
    if (type == "Menu"){
        return new Menu();
    }
    else if (type == "Option"){
        return new Option();
    }
    else if (type == "Raycasting"){
        return new Raycasting();
    }
    else if (type == "3D"){
        return new D3();
    }

    //n'est pas sensé arriver
    return new Menu();
}