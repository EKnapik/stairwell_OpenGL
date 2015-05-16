// Author: Eric M. Knapik
//
// the shader object header file
// this refers to how the shader program to
// be executed depending on the object
// holds all the info for vertex and fragment shaders
#include <GLUT/GLUT.h>
#include <OpenGL/hl.h>
#include "shaderSetup.h"

typedef struct Shader_Struct
{
    GLuint shaderProgram;
    GLfloat rotateVals[3];
    GLfloat transVals[3];
    GLfloat scaleVals[3];
    GLfloat eyePos[3];
    GLfloat lookAt[3];
    GLfloat upVec[3];
    GLfloat left;
    GLfloat right;
    GLfloat top;
    GLfloat bot;
    GLfloat near;
    GLfloat far;

} Shader;


// makes the a shader program with the default values
Shader* mkShader( const char *vert, const char *frag );

// deallocates the memory for the shader object
void destroyShader( Shader *shader);

// sets up the shader variables so that they are passed to the shader
// program for display, must be called before a call to drawTraingles can happen
void shaderDisplay( Shader *shader );

// set camera to something other than default
void setCamera( Shader *shader, GLfloat eyePos[], GLfloat lookAt[], GLfloat upVec[] );

// set rotatation values
// x, y, z
void setRotate( Shader *shader, GLfloat rotateVals[] );

// set translation values
void setTrans( Shader *shader, GLfloat transVals[] );

// set the scale values
void setScale( Shader *shader, GLfloat scaleVals[] );

// sets up all the lighting params, this is a static for the program
// so the program has all the same light
void setUpLighting( Shader *shader );
