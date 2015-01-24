#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Scene;

class StaticObject : public GameObject
{
public:
    StaticObject(Scene* aScene, MyVec2 aPos = MyVec2(0.0f,0.0f), float aAngle = 0.0f);
    ~StaticObject();

    virtual bool Load();

    virtual void Update(double aDelta);
    virtual void Draw();

private:

    Scene* m_Scene;

    sf::RenderWindow* m_Window;

    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
};

#endif