#include "MyVec2.h"
#include<math.h>

MyVec2::MyVec2(float aX, float aY)
{
    x = aX;
    y = aY;
}
MyVec2::~MyVec2()
{

}


//Math Stuff

void MyVec2::AddToMe(MyVec2 aVec2)
{
    x += aVec2.X();
    y += aVec2.Y();
}
void MyVec2::AddToMe(float aFloat)
{
    x += aFloat;
    y += aFloat;
}
void MyVec2::AddToMe(int aInt)
{
    x += (float)aInt;
    y += (float)aInt;
}

void MyVec2::SubtractFromMe(MyVec2 aVec2)
{
    x -= aVec2.X();
    y -= aVec2.Y();
}
void MyVec2::SubtractFromMe(float aFloat)
{
    x -= aFloat;
    y -= aFloat;
}
void MyVec2::SubtractFromMe(int aInt)
{
    x -= (float)aInt;
    y -= (float)aInt;
}

void MyVec2::MultiplyMeBy(MyVec2 aVec2)
{
    x *= aVec2.X();
    y *= aVec2.Y();
}
void MyVec2::MultiplyMeBy(float aFloat)
{
    x *= aFloat;
    y *= aFloat;
}
void MyVec2::MultiplyMeBy(int aInt)
{
    x *= (float)aInt;
    y *= (float)aInt;
}

void MyVec2::DivideMeBy(MyVec2 aVec2)
{
    x /= aVec2.X();
    y /= aVec2.Y();
}
void MyVec2::DivideMeBy(float aFloat)
{
    x /= aFloat;
    y /= aFloat;
}
void MyVec2::DivideMeBy(int aInt)
{
    x /= (float)aInt;
    y /= (float)aInt;
}


//Returns the length of the line
//Used for trigonometry
float MyVec2::Length()
{
    float length;
    length = sqrt( pow( x, 2 ) + pow( y, 2 ) );
    return length;
}



//Member Access

void MyVec2::X(float aNewX)
{
    x = aNewX;
}
float MyVec2::X()
{
    return x;
}

void MyVec2::Y(float aNewY)
{
    y = aNewY;
}
float MyVec2::Y()
{
    return y;
}