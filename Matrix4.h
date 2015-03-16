#ifndef _MATRIX4_H_
#define _MATRIX4_H_

#include "Vector4.h"
#include "Vector3.h"

class Matrix4
{
protected:
    
    float m[4][4];   // matrix elements
    
public:
    
    Matrix4();        // constructor
    Matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
    
    void set(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
    float get(int,int);
    
    Matrix4& operator = (Matrix4);
    
    float* ptr();  // return pointer to matrix elements
    
    void identity();  // create identity matrix
    
    Matrix4 multiply( Matrix4);
    Matrix4 operator * (Matrix4);
    Vector4 multiply( Vector4);
    Vector3 multiply( Vector3);
    
    Matrix4 makeRotateX(float);
    Matrix4 makeRotateY(float); // rotation about y axis
    Matrix4 makeRotateZ(float);
    Matrix4 makeRotateArbitrary(Vector3, float);
    
    Matrix4 makeScale(float,float,float);
    Matrix4 makeScale(float);
    
    Matrix4 makeTranslate(float,float,float);
    
    Matrix4 transpose(void);
    Matrix4 inverse(void);
    Matrix4 orthoNormalInverse(void);
    
    void print(void);
};

#endif
