#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Scene;

class StaticObject : public GameObject
{
public:
    StaticObject(sf::RenderWindow* aWindow);
    StaticObject(Scene* aScene, MyVec2 aPos = MyVec2(0.0f,0.0f), float aAngle = 0.0f);
    ~StaticObject();

    virtual bool Load();

    virtual void Update(double aDelta);
    virtual void Draw();

    sf::Sprite MySprite(){ return m_Sprite; }

private:

    Scene* m_Scene;

    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
};

#endif