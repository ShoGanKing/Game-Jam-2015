#include "GameObject.h"


GameObject::GameObject(MyVec2 aPos, MyVec2 aAngle)
{
    m_Position = aPos;
    m_Angle = aAngle;
    m_Active = false;
}


GameObject::~GameObject()
{

}