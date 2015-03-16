#include "Light.h"
#include "Window.h"
#include <iostream>

#ifdef _WIN32
    #include <GL/glut.h>
#else
    #include <GLUT/glut.h>
#endif


Light::Light()
{
    setAmbientColor(Color::ambientDefault());
    setDiffuseColor(Color::diffuseDefault());
    setSpecularColor(Color::specularDefault());
    
    setConstantAttenuation(1.0);
    setLinearAttenuation(0.0);
    setQuadraticAttenuation(0.05);
}

Light::~Light()
{
    //Delete any dynamically allocated memory/objects here
}


void Light::bind(int id)
{
    if(id < 0 || id > 7) {
        std::cout << "ERROR: The light bind ID " << id << " is not valid!" << std::endl;
        return;
    }
    
    //Set the bindID
    bindID = id;
    
    //Configure the light at the bindID
    glEnable(GL_LIGHT0 + bindID);
    
    //Configure the color of the light
    glLightfv(GL_LIGHT0 + bindID, GL_AMBIENT, ambColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_DIFFUSE, difColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_SPECULAR, spcColor.ptr());
    
    //Configure the attenuation properties of the light
    glLightf(GL_LIGHT0 + bindID, GL_CONSTANT_ATTENUATION, constAtten);
    glLightf(GL_LIGHT0 + bindID, GL_LINEAR_ATTENUATION, linAtten);
    glLightf(GL_LIGHT0 + bindID, GL_QUADRATIC_ATTENUATION, quadAtten);
    
    //Position the light
    glLightfv(GL_LIGHT0 + bindID, GL_POSITION, position.ptr());
    
    //Setup spotlight direction, angle, and exponent here
}

void Light::unbind(void)
{
    glDisable(GL_LIGHT0 + bindID);
    bindID = -1;
}


void Light::setAmbientColor(Color c)  {ambColor = c;}
Color Light::getAmbientColor()        {return ambColor;}

void Light::setDiffuseColor(Color c)  {difColor = c;}
Color Light::getDiffuseColor()        {return difColor;}

void Light::setSpecularColor(Color c) {spcColor = c;}
Color Light::getSpecularColor()       {return spcColor;}


void Light::setConstantAttenuation(float c)
{
    constAtten = c;
}

float Light::getConstantAttenuation(void)
{
    return constAtten;
}

void Light::setLinearAttenuation(float c)
{
    linAtten = c;
}

float Light::getLinearAttenuation(void)
{
    return linAtten;
}

void Light::setQuadraticAttenuation(float c)
{
    quadAtten = c;
}

float Light::getQuadraticAttenuation(void)
{
    return quadAtten;
}

void Light::setPosition(Vector4 & pos)
{
    position = pos;
}

Vector4 Light::getPosition()
{
    return position;
}


