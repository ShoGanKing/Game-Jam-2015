#include "GameObject.h"


GameObject::GameObject(MyVec2 aPos, float aAngle)
{
    m_Position = aPos;
    m_Angle = aAngle;
    m_Active = false;
}


GameObject::~GameObject()
{

}