#ifndef BIRDOBJECT_H
#define BIRDOBJECT_H

#include"GameObject.h"
#include"ActiveGameObject.h"
#include <SFML/Graphics.hpp>

class Scene;
class MyVec2;



class BirdObject : public ActiveGameObject
{
public:
    BirdObject(Scene* aScene, MyVec2 aPos = MyVec2(0.0f, 0.0f), float aAngle = 0.0f, MyVec2 aVelocity = MyVec2(0.0f, 0.0f));
    ~BirdObject();

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();

    void SetPosition(MyVec2 aPosition);

    MyVec2 GetVelocity();
    void SetVelocity(MyVec2 aVelocity);

    sf::Sprite* MySprite(){ return &m_Sprite; }

protected:

    MyVec2 m_Velocity;

    Scene* m_Scene;

    unsigned short m_Frame;
    sf::Time m_Time;

    sf::Texture m_Texture;
    sf::Texture m_Texture2;
    sf::Texture m_Texture3;
    sf::Texture m_Texture4;
    sf::Sprite m_Sprite;


    sf::Texture m_PressedTexture;
    sf::Sprite m_PressedSprite;

};

#endif