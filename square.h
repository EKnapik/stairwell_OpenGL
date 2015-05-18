// square.h
// Author: Eric M. Knapik
// header file


#ifndef SQUARE
#define SQUARE

#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


GLfloat* getSquareVerticies( void );

GLfloat* getSquareNorms( void );

GLint getSquareNumVert( void );

GLshort* getSquareConnectData( void );

#endif
