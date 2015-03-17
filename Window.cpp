#include <iostream>

#ifdef _WIN32
    #include <GL/glut.h>
#else
    #include <GLUT/glut.h>
#endif

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "Globals.h"

using namespace std;

int Window::width  = 512;   //Set window width in pixels here
int Window::height = 512;   //Set window height in pixels here


void Window::initialize(void)
{
    //Setup the light
    Vector4 lightPos(0.0, 10.0, 15.0, 1.0);
    Globals::light.setPosition(lightPos);
    Globals::light.setQuadraticAttenuation(0.02);
    
    //Initialize cube matrix:
    Globals::cube.toWorld.identity();
    
    //Setup the cube's material properties
    Color color(0x23ff27ff);
    Globals::cube.material.setColor(color);
}

//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback()
{
    //Set up a static time delta for update calls
    Globals::updateData.dt = 1.0/60.0;// 60 fps
    
    //Rotate cube; if it spins too fast try smaller values and vice versa
    Globals::cube.spin(0.0005);
    
    //Call the update function on cube
    Globals::cube.update(Globals::updateData);
    
    //Call the display routine to draw the cube
    displayCallback();
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, w, h);  //Set new viewport size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, double(width)/(double)height, 1.0, 1000.0); //Set perspective projection viewing frustum
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
    //Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glLoadMatrixf(Globals::camera.getInverseMatrix().ptr());
    
    //Bind the light to slot 0.  We do this after the camera matrix is loaded so that
    //the light position will be in world coordiantes (otherwise it would be in
    //camera coordiantes, why is that?)
    Globals::light.bind(0);
    
    //Draw the cube!
    Globals::cube.draw(Globals::drawData);
    
    glPopMatrix();
    
    //Tell OpenGL to clear any outstanding commands in its command buffer
    //This will make sure that all of our commands are fully executed before
    //we swap buffers and show the user the freshly drawn frame
    glFlush();
    
    //Swap the off-screen buffer (the one we just drew to) with the on-screen buffer
    glutSwapBuffers();
}




//TODO: Keyboard callbacks!

//TODO: Function Key callbacks!
