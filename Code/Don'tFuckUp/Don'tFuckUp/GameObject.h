#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "MyVec2.h"

class GameObject
{
public:
    GameObject( MyVec2 aPos, float aAngle = 0.0f );
    ~GameObject();

    bool IsActive();

    virtual bool Load() = 0;

    virtual void Update(double aDelta) = 0;
    virtual void Draw() = 0;

protected:
    float m_Angle;
    MyVec2 m_Position;

    bool m_Active;

};

#endif