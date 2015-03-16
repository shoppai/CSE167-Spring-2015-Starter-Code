#ifndef __CSE167_Proj4__Material__
#define __CSE167_Proj4__Material__

#include <iostream>
#include "Color.h"

class Material
{
    
protected:
    
    Color ambColor;
    Color difColor;
    Color spcColor;
    Color emiColor;
    
    float shininess;
    
public:
    
    Material(void);
    ~Material(void);
    
    
    virtual void apply(void);
    
    
    void setAmbientColor(Color c)  { ambColor = c; }
    Color getAmbientColor()        { return ambColor; }
    
    void setDiffuseColor(Color c)  { difColor = c; }
    Color getDiffuseColor()        { return difColor; }
    
    void setSpecularColor(Color c) { spcColor = c; }
    Color getSpecularColor()       { return spcColor; }
    
    void setEmissionColor(Color c) { emiColor = c; }
    Color getEmissionColor()       { return emiColor; }
    
    
    void setShininess(float s)     { shininess = s; }
    float getShininess(void)       { return shininess; }
    
};

#endif /* defined(__CSE167_Proj4__Material__) */
