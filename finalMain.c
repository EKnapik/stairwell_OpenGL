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

#include "shaderSetup.h"


#define INITIAL_HEIGHT 750
#define INITIAL_WIDTH 750



void createBuffers( )
{
    // get and load the verticies for your shape
    float *points = vertexArray;
    int dataSize = numVerts * 4 * sizeof( float );

    // get and load the element data or connectivity
    GLushort *elements = elementArray;
    int elementDataSize = numVerts * sizeof( GLushort );

    // ask OpenGL for ONE  buffer object ID
    glGenBuffers( 1, &vbuffer );

    // State what kind of buffer we want to refer to
    // OpenGL can only have have one type of buffer be the current one
    // This is have the vbuffer be our current GL_ARRAY_BUFFER
    glBindBuffer( GL_ARRAY_BUFFER, vbuffer );

    // Load our data and connect it to our vbuffer object so we can
    // refer to it later just by binding the vbuffer object
    // type of data, the size in bytes, the data itself, how to draw it
    glBufferData( GL_ARRAY_BUFFER, dataSize, points, GL_STATIC_DRAW );

    // Some programs at this point have a global value of whether we have
    // initialized our buffer yet and this would be done right here


    // Similar process for the connectivity/element data
    glGenBuffers( 1, &ebuffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, elementDataSize, elements, GL_STATIC_DRAW );


    // Stop having these buffers bound to the current OpenGL buffers
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
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

    // bind the vertex buffer you want to use
    glBindBuffer( GL_ARRAY_BUFFER, vbuffer );

    // bind the element buffer you want to use
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebuffer );

    // Which shader program should I use and what data will it be getting
    glUseProgram( program );

    // This is where you give the data to uniform variables and state how arrib
    // variables should get their data

    // how to look at my GL_ARRAY_BUFFER for vertex data
    // the object data ID, how many make up one, data type, should I transpose?,
    // step, beginning offset

    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 0 );

    glUniformMatrix4fv( transformLocation, 1, GL_FALSE, &transformMatrix );


    // everything is loaded now draw the shape with current buffers and shader program
    glDrawElements( GL_TRIANGLES, numVerts, GL_UNSIGNED_SHORT, (void *)0);


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


    glutMainLoop();

    return 0; // This is actually never called
    // When glutMainLoop(); ends it will exit the program
}

