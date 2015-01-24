#ifndef MYVEC2_H
#define MYVEC2_H

class MyVec2
{
public:
    MyVec2(float aX = 0.0f, float aY = 0.0f);
    ~MyVec2();

    //Math methods
    void AddToMe(MyVec2 aVec2);
    void AddToMe(float aFloat);
    void AddToMe(int aInt);

    void SubtractFromMe(MyVec2 aVec2);
    void SubtractFromMe(float aFloat);
    void SubtractFromMe(int aInt);

    void MultiplyMeBy(MyVec2 aVec2);
    void MultiplyMeBy(float aFloat);
    void MultiplyMeBy(int aInt);

    void DivideMeBy(MyVec2 aVec2);
    void DivideMeBy(float aFloat);
    void DivideMeBy(int aInt);

    float Length();

    //Member Access
    void X(float aNewX);
    float X();

    void Y(float aNewY);
    float Y();

private:
    float x;
    float y;

};

#endif