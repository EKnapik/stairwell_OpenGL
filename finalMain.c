// Final for CSCI 510
// Author: Eric M. Knapik

/**
* These are the two main includes that are required
* to open a window using openGL, the GLUT is a windowing
* API which will actually make openGL calls for you, but
* since they are very terse and will change depending on the system
* I just use GLUT.
*
*
* As for gl.h this is the openGL header file found under OpenGL
* Mac maintains the current version of openGL and is backwards compatible
* I think
**/
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "object.h"
#include "cylinder.h"

#define INITIAL_HEIGHT 750
#define INITIAL_WIDTH 750

// Making this a global for now
// idea is to pass all objects to the display function
// from the main, or just make them all global
Object *cylinder;

/**
* Make a cylinder
**/
void mkCylinder( void )
{
    cylinder = mkObject( "cylinder.vert", "cylinder.frag" );
    // add the data to the object
    addVerticies( cylinder, getCylinderVerticies(), getCylinderNorms(),
    getCylinderConnectData(), getCylinderNumVert(), getCylinderNumVert() );
    // setup my buffers for this object
    setupGLBuffers( cylinder );
    
    GLfloat translation[] = { 0, 0, -2 };
    setTrans( cylinder->shader, translation );

    GLfloat scale[] = {2, 2, 2};
    setScale( cylinder->shader, scale );

    GLfloat rotate[] = {90, 30, 0};
    setRotate( cylinder->shader, rotate );

    //return cylinder;
}



/**
* Clear our frame buffers
* load the values/data for shaders, when loading these it is assumed
* that the shader program you are loading to is the one currently in use
*
* Bind the buffer you want to get your points from
* draw the points from the buffer in some way
*
* load next buffer if you want (draw another object)
*
* update your internal representation of object position for collisions and stuff
* perform all checks that you want
*
* unbind any currently bound buffers
* glFlush(); // glutSwapBuffers does this
*
* swapBuffers
**/
void display( void )
{
    // clear your frame buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    drawObject( cylinder );    

    // swap the buffers -> makes what you rendered to the screen facing buffer
    glutSwapBuffers();
    glutPostRedisplay(); // Tell glut to render another frame
}

void setupGLUT( int argc, char *argv[] )
{
    glutInit( &argc, argv );

    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );

    // INITIAL_HEIGHT this is used to set how big the window is
    glutInitWindowSize( INITIAL_HEIGHT, INITIAL_WIDTH );
    glutCreateWindow( "Final Project" ); // look at that nice title <-

    glEnable( GL_DEPTH_TEST );
    glEnable( GL_CULL_FACE );

    // Set the background color
    glClearColor( 0.0, 0.0, 0.0, 0.0 );

    // Sets the color of the cull faces to the background color
    glCullFace( GL_BACK );

    // Want to draw wire frames us GL_LINE
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    // Sets up the display function
    glutDisplayFunc( display );

}



int main( int argc, char *argv[] )
{
    // initialize my GLUT window
    setupGLUT( argc, argv );

    // create an array of Objects to draw
    // each object has a buffer creation method
    // shader program creation
    // and how to run its display method
    
    // make the cylinder
    mkCylinder();

    glutMainLoop();

    return 0; // This is actually never called
    // When glutMainLoop(); ends it will exit the program
}

