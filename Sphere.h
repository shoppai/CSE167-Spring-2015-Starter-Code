#ifndef __CSE167_Proj5__Sphere__
#define __CSE167_Proj5__Sphere__

#include <iostream>
#include "Drawable.h"

class Sphere : public Drawable
{
    
public:
    
    double radius;
    int slices, stacks;
    
    Sphere(double, int, int);
    
    virtual void draw(DrawData&);
    virtual void update(UpdateData&);
    
};


#endif /* defined(__CSE167_Proj5__Sphere__) */
