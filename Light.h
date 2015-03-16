#ifndef __CSE167_Proj4__Light__
#define __CSE167_Proj4__Light__

#include "Matrix4.h"
#include "Color.h"
#include <vector>

class Light
{
    
protected:
    
    Vector4 position;
    
    int bindID = -1;
    
    Color ambColor;
    Color difColor;
    Color spcColor;
    
    float constAtten;
    float linAtten;
    float quadAtten;
    
public:
    
    Light();
    ~Light(void);
    
    void bind(int);
    void unbind(void);
    
    
    void setAmbientColor(Color);
    Color getAmbientColor();
    
    void setDiffuseColor(Color);
    Color getDiffuseColor();
    
    void setSpecularColor(Color);
    Color getSpecularColor();
    
    
    void setConstantAttenuation(float);
    float getConstantAttenuation(void);
    
    void setLinearAttenuation(float);
    float getLinearAttenuation(void);
    
    void setQuadraticAttenuation(float);
    float getQuadraticAttenuation(void);
    
    void setPosition(Vector4&);
    Vector4 getPosition();
    
};


#endif /* defined(__CSE167_Proj4__Light__) */
