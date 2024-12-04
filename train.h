#pragma once
#include <iostream>
class Coordinates 
{
    private:
    float x;
    float y;
    float z;
    public:
    explicit Coordinates(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}
    Coordinates(const Coordinates& obj);
    Coordinates operator++(int);
    Coordinates operator--(int);
    friend float operator++(Coordinates& crd_1);
    Coordinates operator--();
    bool operator!=(Coordinates& second);
    bool operator==(Coordinates& second);
    float getX() 
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float getZ() 
    {
        return z;
    }
    void setCoord(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ~Coordinates() 
    {
        x = 0;
        y = 0;
        z = 0;
    }
};