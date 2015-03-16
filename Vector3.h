#ifndef CSE167_Proj1_Vector3_h
#define CSE167_Proj1_Vector3_h

class Vector3
{
protected:
    
    float m[3];
    
public:
    
    Vector3();
    Vector3(float, float, float);
    virtual ~Vector3(void);
    
    float* ptr();
    
    //Public methods go here
    void set(float, float, float);
    void set(int index, float value);
    float get(int);
    float& operator [] (int);
    
    Vector3 add(Vector3);
    Vector3 operator + (Vector3);
    
    Vector3 subtract(Vector3);
    Vector3 operator - (Vector3);
    
    Vector3 negate(void);
    Vector3 scale(float);
    Vector3 multiply(Vector3);
    Vector3 operator * (Vector3);
    Vector3 multiply(float);
    Vector3 operator * (float);
    
    float dot(Vector3);
    Vector3 cross(Vector3);
    
    float angle(Vector3);
    
    float magnitude(void);
    
    Vector3 normalize(void);
    
    void print(void);
};

#endif
