#include "Material.h"

#ifdef _WIN32
    #include <GL/glut.h>
#else
    #include <GLUT/glut.h>
#endif

Material::Material()
{
    //Material setup goes hurr
    setAmbientColor(Color::ambientMaterialDefault());
    setDiffuseColor(Color::diffuseMaterialDefault());
    setSpecularColor(Color::specularMaterialDefault());
    setEmissionColor(Color::emissionMaterialDefault());
    setShininess(10.0);
    
    //Set the initial color to a random pastel color
    //Can be removed once materials are implemented
    setColor(Color::randomPastel());
}

Material::~Material()
{
    //Delete any dynamically allocated memory/objects here
}

void Material::apply(void)
{
    //Set the material properties for ambient, diffuse, specular, emission, and shininess
    //Hint: Lookup how glMaterialfv works
    
    //Set the color property (can be removed once materials are implemented)
    //Used for projects 1, 2, and 3
    glColor3fv(color.ptr());
}



