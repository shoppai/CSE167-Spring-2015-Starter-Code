#include "Vector3.h"
#include <math.h>
#include <iostream>
#include <cstring>

Vector3::Vector3()
{
    std::memset(m, 0, sizeof(m));
}

Vector3::Vector3(float m0, float m1, float m2)
{
    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
}

Vector3::~Vector3()
{
    //
}

float* Vector3::ptr()
{
    return &m[0];
}

void Vector3::set(float x, float y, float z)
{
    m[0] = x;
    m[1] = y;
    m[2] = z;
}

void Vector3::set(int index, float value)
{
    m[index] = value;
}

float Vector3::get(int loc)
{
    return m[loc];
}

float& Vector3::operator [] (int loc)
{
    return m[loc];
}

Vector3 Vector3::add(Vector3 a)
{
    Vector3 temp;
    
    //
    
    return temp;
}

Vector3 Vector3::operator + (Vector3 a)
{
    return add(a);
}

Vector3 Vector3::subtract(Vector3 a)
{
    Vector3 temp;
    
    //
    
    return temp;
}

Vector3 Vector3::operator - (Vector3 a)
{
    return subtract(a);
}

Vector3 Vector3::negate(void)
{
    Vector3 temp;
    
    //
    
    return temp;
}

Vector3 Vector3::scale(float s)
{
    Vector3 temp;
    
    //
    
    return temp;
}

Vector3 Vector3::operator * (float s)
{
    return scale(s);
}


float Vector3::dot(Vector3 a)
{
    //
    
    return 0.0;
}

Vector3 Vector3::cross(Vector3 a)
{
    Vector3 temp;
    
    //
    
    return temp;
}

float Vector3::angle(Vector3 a)
{
    //
    
    return 0.0;
}

float Vector3::magnitude(void)
{
    //
    
    return 0.0;
}

Vector3 Vector3::normalize(void)
{
    Vector3 temp;
    
    //
    
    return temp;
}

void Vector3::print(void)
{
    std::cout << "<x:" << m[0] <<  ", y:" << m[1] << ", z:" << m[2] << ">" << std::endl;
}
