#ifndef CSE167_Light_h
#define CSE167_Light_h

#include "Matrix4.h"
#include "Color.h"
#include <vector>

class Light
{
    
protected:
    
    int bindID = -1;
    
public:
    
    Vector4 position;
    
    Color ambientColor;
    Color diffuseColor;
    Color specularColor;
    
    float constantAttenuation;
    float linearAttenuation;
    float quadraticAttenuation;
    
public:
    
    Light();
    virtual ~Light(void);
    
    void bind(int);
    void unbind(void);
    
};


#endif /* defined(__CSE167_Proj4__Light__) */
