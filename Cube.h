#ifndef _CUBE_H_
#define _CUBE_H_

#include "Drawable.h"

class Cube : public Drawable
{
    
public:
    
    float size;
    
    Cube(float);
    
    virtual void draw(DrawData&);
    virtual void update(UpdateData&);
    
    void spin(float);
};



#endif

