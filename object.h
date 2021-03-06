// object.h
// Author: Eric M. Knapik
// header file for the object struct

#ifndef ObjectClass
#define ObjectClass

#include <SOIL/SOIL.h>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <stdlib.h>
#include <stdio.h>

#include "shader.h"

// Define the struct of my object
typedef struct Object_Struct
{
    GLfloat *verticies;
    GLfloat *normals;
    GLshort *connectivity;
    GLfloat *uvs;
    GLuint  numVerts;
    GLuint numConnect;

    GLuint textBufferID;
    GLuint texCoordID;
    GLuint texID;
    const char *texFile;

    GLuint  vBuffer;
    GLuint  eBuffer;
    Shader  *shader;

} Object;

// The object may gain a new variable a shader object
// This shader object has the shader program id
// the matricies required for the shader
// the light and material properties

// the object creation method
Object* mkObject( const char *texFile, const char *vert, const char *frag );

// the object deletion method
void destroyObject( Object *object );

// can give an array of verticies for the object
void addVerticies( Object *object, GLfloat *verts, GLfloat *vertNorms,
                   GLshort *connections, GLuint numVerts, GLuint numConnect, GLfloat *uvs );

// can add an individual triangle to the object mesh must be counter clockwise
void addTriangle( Object *object, GLfloat x1, GLfloat y1, GLfloat z1, 
                  GLfloat x2, GLfloat y2, GLfloat z2,
                  GLfloat x3, GLfloat y3, GLfloat z3 );

// given the verticies and the connectivity data will compute
// and set the normals at each vertex averaging the normals of the
// connecting faces
void findAverageNormals( Object *object );

// when ready setup the vBuffer and the eBuffer
void setupGLBuffers( Object *object );

// draw the current object
void drawObject( Object *object );

#endif
