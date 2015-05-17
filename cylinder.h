// Cylinder.h
// AUthor: Eric M. Knapik
// header file


#ifndef CYLINDER
#define CYLINDER

#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


GLfloat* getCylinderVerticies( void );

GLfloat* getCylinderNorms( void );

GLint getCylinderNumVert( void );

GLshort* getCylinderConnectData( void );

#endif
