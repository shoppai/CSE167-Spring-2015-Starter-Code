#ifndef CSE167_Proj1_Vector4_h
#define CSE167_Proj1_Vector4_h
class Vector3;
class Vector4
{
protected:
    
    float m[4];   // matrix elements
    
public:
    
    Vector4();        // constructor
    Vector4(float, float, float);
    Vector4(float, float, float, float);
    
    float* ptr();
    float& operator [] (int);
    
    //Public methods go here
    void set(float,float,float,float);
    float get(int);
    
    
    Vector4 add(Vector4&);
    Vector4 operator + (Vector4);
    
    Vector4 subtract(Vector4&);
    Vector4 operator - (Vector4);
    
    void dehomogenize();
    
    
    Vector3 toVector3();
    
    float dot(Vector4);
    
    void print(void);
};

#endif
