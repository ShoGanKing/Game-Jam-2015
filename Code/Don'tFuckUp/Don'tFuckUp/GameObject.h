#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include"MyVec2.h"

class GameObject
{
public:
    GameObject( MyVec2 aPos, std::string aType, float aAngle = 0.0f );
    ~GameObject();

    bool IsActive();
    void SetIsActive(bool aActive);

    std::string GetType();

    MyVec2 GetPosition();
    virtual void SetPosition(MyVec2 aPosition);

    float GetAngle();
    void SetAngle(float aAngle);

    virtual bool Load() = 0;
    virtual void Update(sf::Time aDelta) = 0;
    virtual void Draw() = 0;

protected:
    float m_Angle;
    MyVec2 m_Position;

    sf::RenderWindow* m_Window;

    std::string m_Type;

    bool m_Active;

};

#endif