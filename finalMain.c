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
#include "square.h"

#define INITIAL_HEIGHT 750
#define INITIAL_WIDTH 750

// ComplexObject Struct
typedef struct ComplexObjectStruct
{
    Object **object;
    int numObjects;
} ComplexObject;




// Making this a global for now
// idea is to pass all objects to the display function
// from the main, or just make them all global
Object *cylinder1, *cylinder2, *cylinder3, *cylinder4;;
Object *baseGround;
ComplexObject *stairSet1, *stairSet2, *stairSet3;

/**
* Make a cylinder
**/
Object* mkCylinder( float xTrans, float zTrans )
{
    Object *cylinder = mkObject( "stepsScene.vert", "stepsScene.frag" );
    // add the data to the object
    addVerticies( cylinder, getCylinderVerticies(), getCylinderNorms(),
    getCylinderConnectData(), getCylinderNumVert(), getCylinderNumVert() );
    // setup my buffers for this object
    setupGLBuffers( cylinder );
    
    GLfloat translation[] = { xTrans, 25, zTrans };
    setTrans( cylinder->shader, translation );

    GLfloat scale[] = {2.5, 2.5, 50};
    setScale( cylinder->shader, scale );

    GLfloat rotate[] = {90, 0, 0};
    setRotate( cylinder->shader, rotate );

    return cylinder;
}

/**
* Make a square
**/
Object* mkLanding( float height, float angle, float xTrans, float zTrans )
{
    Object *landing = mkObject( "stepsScene.vert", "stepsScene.frag" );
    // add the data to the object
    addVerticies( landing, getSquareVerticies(), getSquareNorms(),
    getSquareConnectData(), getSquareNumVert(), getSquareNumVert() );

    // setup my buffers for this object
    setupGLBuffers( landing );
 
    GLfloat translation[] = { xTrans, height, zTrans };
    setTrans( landing->shader, translation );

    GLfloat scale[] = {2, .25, 1};
    setScale( landing->shader, scale );

    GLfloat rotate[] = {0, angle, 0};
    setRotate( landing->shader, rotate );

    return landing;
}


/**
* This makes a step, this will be called procedurally
* to make several steps for each set of steps
**/
Object* makeStep( float height, float angle, float xTrans, float zTrans )
{
    Object *step = mkObject( "stepsScene.vert", "stepsScene.frag" );
    // add the data to the object
    addVerticies( step, getSquareVerticies(), getSquareNorms(),
    getSquareConnectData(), getSquareNumVert(), getSquareNumVert() );

    // setup my buffers for this object
    setupGLBuffers( step );
 
    float xDisp = 1.5 * cos( angle * 3.14159 / 180 );
    float zDisp = -1.5 * sin( angle * 3.14159 / 180 );

    GLfloat translation[] = { xDisp + xTrans, height, zDisp + zTrans};
    setTrans( step->shader, translation );

    // The scale for the step
    // it is 1x.25x.25
    GLfloat scale[] = {.75, .25, .25};
    setScale( step->shader, scale );

    GLfloat rotate[] = {0, angle, 0};
    setRotate( step->shader, rotate );

    return step;
}

/**
* Makes a stair set, this is 13 steps each at an angle of 3.38 degrees off
* each step leads to a platform that is at the same level as that last step
* platforms center are at the 90, 180, 270, and 0 degrees of a circle
**/
ComplexObject* mkStairSet( float firstHeight, float baseAngle,
                float xTrans, float zTrans )
{
    ComplexObject *stairSet = malloc( sizeof( ComplexObject ) );
    if( stairSet == NULL )
    {
        perror( "Could not malloc for stairset\n" );
        exit( 1 );
    }

    // there are 13 stairs in a stairSet
    stairSet->numObjects = 14;
    stairSet->object = malloc( sizeof( Object* ) * 13 );
    float currentAngle = baseAngle;
    float currentHeight = firstHeight;

    for( int i = 0; i < 13; i++ )
    {
        stairSet->object[i] = makeStep( currentHeight, currentAngle,
                              xTrans, zTrans );
        currentHeight += .25;
        currentAngle -= 4.4;
    }
 
    int diff = ((int) baseAngle) % 90;
    currentHeight -= .25;
    currentAngle = baseAngle - diff;
    float xDisp = 2 * cos( currentAngle * 3.14159 / 180 );
    float zDisp = -2 * sin( currentAngle * 3.14159 / 180 );


    stairSet->object[13] = mkLanding( currentHeight, currentAngle,
                           xDisp + xTrans, zDisp + zTrans );

    return stairSet;
}



/**
* Make the base ground
**/
void mkBase( void )
{
    baseGround = mkObject( "stepsScene.vert", "stepsScene.frag" );
    // add the data to the object
    addVerticies( baseGround, getSquareVerticies(), getSquareNorms(),
    getSquareConnectData(), getSquareNumVert(), getSquareNumVert() );

    // setup my buffers for this object
    setupGLBuffers( baseGround );
    
    GLfloat scale[] = {10, .25, 10};
    setScale( baseGround->shader, scale );
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

    // draw base
    // drawObject( baseGround );

    // draw test staircase with landing at the top
    for( int i = 0; i < stairSet1->numObjects; i++ )
    {
        drawObject( stairSet1->object[i] );
        drawObject( stairSet2->object[i] );
    }

    // draw the cylinder Column
    drawObject( cylinder1 );
    drawObject( cylinder2 );
    drawObject( cylinder3 );
    drawObject( cylinder4 );


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

    // make the baseLayer my ground in the scene, it appears to be a stone
    // mkBase();
    stairSet1 = mkStairSet( 0, 245, 1, -3 );
    stairSet2 = mkStairSet( 3.25, 345, -3, -3 );
    
    // make cylinder
    cylinder1 = mkCylinder(1, -3);
    cylinder2 = mkCylinder(-3, -3);
    cylinder3 = mkCylinder(-3, 1);
    cylinder4 = mkCylinder(1, 1);

    


    glutMainLoop();

    return 0; // This is actually never called
    // When glutMainLoop(); ends it will exit the program
}

