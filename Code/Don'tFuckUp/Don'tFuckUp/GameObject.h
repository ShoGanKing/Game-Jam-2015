#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "MyVec2.h"

class GameObject
{
public:
    GameObject( MyVec2 aPos, MyVec2 aAngle = MyVec2(0.0, 1.0) );
    ~GameObject();

    bool IsActive(){ return m_Active; }

    virtual bool Load() = 0;

    virtual void Update(double aDelta) = 0;
    virtual void Draw() = 0;

private:
    MyVec2 m_Angle;
    MyVec2 m_Position;

    bool m_Active;

};

#endif