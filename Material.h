#ifndef CSE167_Material_h
#define CSE167_Material_h

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
    
    //A color variable used in Projects 1, 2, and 3
    //This can be removed once materials are implemented
    Color color;
    
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
    
    
    void setColor(Color c) { color = c; }
    Color getColor()       { return color; }
    
};

#endif /* defined(__CSE167_Proj4__Material__) */
