#include "Vector3.h"
#include <math.h>
#include <iostream>
#include <cstring>
#include "Vector4.h"

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

float& Vector3::operator [] (int loc)
{
    return m[loc];
}

Vector3 Vector3::add(Vector3 a)
{
    Vector3 b;
    
    // Implementation
    b.set(b[0] + a[0], b[1] + a[1], b[2] + a[2]);
    
    return b;
}

Vector3 Vector3::operator + (Vector3 a)
{
    return add(a);
}

Vector3 Vector3::subtract(Vector3 a)
{
    Vector3 b;
    
    // Implementation
    b.set(b[0] - a[0], b[1] - a[1], b[2] - a[2]);
    
    return b;
}

Vector3 Vector3::operator - (Vector3 a)
{
    return subtract(a);
}

Vector3 Vector3::negate(void)
{
    Vector3 b;
    
    // Implementation
    b.set(-1*b[0], -1*b[1], -1*b[2]);
    
    return b;
}

Vector3 Vector3::scale(float s)
{
    Vector3 b;
    
    // Implementation
    b.set(s*b[0], s*b[1], s*b[2]);
    
    return b;
}

Vector3 Vector3::multiply(float a)
{
    Vector3 b;
    
    // Implementation
    b.set(a*b[0], a*b[1], a*b[2]);
    
    return b;
}

Vector3 Vector3::operator * (float a)
{
    return multiply(a);
}

Vector3 Vector3::multiply(Vector3 a)
{
    Vector3 b;
    
    //Coomponent-wise multiplication
    b.set(m[0]*a[0], m[1]*a[1], m[2]*a[2]);
    
    return b;
}

Vector3 Vector3::operator * (Vector3 a)
{
    return multiply(a);
}


float Vector3::dot(Vector3 a)
{
    // Implementation
    float result = (a[0] * m[0]) + (a[1] * m[1]) + (a[2] * m[2]);
    
    return result;
}

Vector3 Vector3::cross(Vector3 a)
{
    Vector3 b;
    
    // Implementation
    float x = (m[1] * a[2]) - (m[2] * a[1]);
    float y = (m[2] * a[0]) - (m[0] * a[2]);
    float z - (m[0] * a[1]) - (m[1] * a[0]);
    
    b.set(x, y, z);
    
    return b;
}

float Vector3::angle(Vector3 a)
{
    // Implementation
    float dot = dot(a);
    float magnitude = magnitude() * magnitude();
    float angle = acos(dot / magnitude);
    
    return angle;
}

float Vector3::magnitude(void)
{
    // Implementation
    float result = (m[0] * m[0]) + (m[1] * m[1]) + (m[2] * m[2]);
    
    return result;
}

Vector3 Vector3::normalize(void)
{
    Vector3 b;
    
    // Implementation
    float magnitude = magnitude();
    
    if (magnitude != 0){
        float x = m[0] / magnitude;
	    float y = m[1] / magnitude;
		float z = m[2] / magnitude;
		b.set(x, y, z);
    }    
    
    return b;
}

Vector4 Vector3::toVector4(float w)
{
    Vector4 b(m[0], m[1], m[2], w);
    return b;
}

void Vector3::print(std::string comment)
{
    std::cout << comment << std::endl;
    std::cout << "<x:" << m[0] <<  ", y:" << m[1] << ", z:" << m[2] << ">" << std::endl;
}
