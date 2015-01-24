#ifndef ACTIVEGAMEOBJECT_H
#define ACTIVEGAMEOBJECT_H

#include"GameObject.h"
#include <SFML/Graphics.hpp>

class Scene;
class MyVec2;

class ActiveGameObject : public GameObject
{
public:
    ActiveGameObject(Scene* aScene, MyVec2 aPos = MyVec2(0.0f, 0.0f), float aAngle = 0.0f, MyVec2 aVelocity = MyVec2(0.0f,0.0f));
    ~ActiveGameObject();

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();

    void SetPosition(MyVec2 aPosition);

    MyVec2 GetVelocity();
    void SetVelocity(MyVec2 aVelocity);

    sf::Sprite MySprite(){ return m_Sprite; }

protected:

    MyVec2 m_Velocity;

    Scene* m_Scene;

    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
};

#endif