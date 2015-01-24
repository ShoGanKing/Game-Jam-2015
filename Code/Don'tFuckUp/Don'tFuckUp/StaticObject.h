#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
    StaticObject();
    ~StaticObject();

    virtual bool Load();

    virtual void Update(double aDelta);
    virtual void Draw();

private:

    sf::Texture m_Texture;
    sf::Sprite m_Player;
};

#endif