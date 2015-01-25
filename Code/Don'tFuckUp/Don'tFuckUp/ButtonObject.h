#ifndef BUTTONOBJECT_H
#define BUTTONOBJECT_H

#include"GameObject.h"
#include <SFML/Graphics.hpp>

class Scene;
class MyVec2;

enum Input_Events;


class ButtonObject : public ActiveGameObject
{
public:
    ButtonObject(Input_Events aType, Scene* aScene, MyVec2 aPos = MyVec2(0.0f, 0.0f), float aAngle = 0.0f, MyVec2 aVelocity = MyVec2(0.0f, 0.0f));
    ~ButtonObject();

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();

    void SetPosition(MyVec2 aPosition);

    void PressButton(bool aDown);

    Input_Events MyType();

    MyVec2 GetVelocity();
    void SetVelocity(MyVec2 aVelocity);

    sf::Sprite* MySprite(){ return &m_Sprite; }

protected:

    MyVec2 m_Velocity;

    Scene* m_Scene;

    Input_Events m_Type;

    bool m_IsPressed;

    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
    sf::Texture m_PressedTexture;
    sf::Sprite m_PressedSprite;

};

#endif