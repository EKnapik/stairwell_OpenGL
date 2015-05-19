// Cylinder.c
// Author: Eric M. Knapik
// This is the verticies and normals for the side of
// a cylinder, the tops and bottom are not included

#include "cylinder.h"

/**
* Returns the verticies that define the side of the cylinder
* the top and bottom of the cylinder are not added to this
**/
GLfloat* getCylinderVerticies( void )
{
    GLfloat verts[] = {
    0.50, 0.00, 0.50, 1, 0.50, 0.00, 0.25, 1, 0.46, 0.19, 0.25, 1,
    0.46, 0.19, 0.50, 1, 0.50, 0.00, 0.50, 1, 0.46, 0.19, 0.25, 1,
    0.50, 0.00, 0.25, 1, 0.50, 0.00, 0.00, 1, 0.46, 0.19, 0.00, 1,
    0.46, 0.19, 0.25, 1, 0.50, 0.00, 0.25, 1, 0.46, 0.19, 0.00, 1,
    0.50, 0.00, 0.00, 1, 0.50, 0.00, -0.25, 1, 0.46, 0.19, -0.25, 1,
    0.46, 0.19, 0.00, 1, 0.50, 0.00, 0.00, 1, 0.46, 0.19, -0.25, 1,
    0.50, 0.00, -0.25, 1, 0.50, 0.00, -0.50, 1, 0.46, 0.19, -0.50, 1,
    0.46, 0.19, -0.25, 1, 0.50, 0.00, -0.25, 1, 0.46, 0.19, -0.50, 1,
    0.46, 0.19, 0.50, 1, 0.46, 0.19, 0.25, 1, 0.35, 0.35, 0.25, 1,
    0.35, 0.35, 0.50, 1, 0.46, 0.19, 0.50, 1, 0.35, 0.35, 0.25, 1,
    0.46, 0.19, 0.25, 1, 0.46, 0.19, 0.00, 1, 0.35, 0.35, 0.00, 1,
    0.35, 0.35, 0.25, 1, 0.46, 0.19, 0.25, 1, 0.35, 0.35, 0.00, 1,
    0.46, 0.19, 0.00, 1, 0.46, 0.19, -0.25, 1, 0.35, 0.35, -0.25, 1,
    0.35, 0.35, 0.00, 1, 0.46, 0.19, 0.00, 1, 0.35, 0.35, -0.25, 1,
    0.46, 0.19, -0.25, 1, 0.46, 0.19, -0.50, 1, 0.35, 0.35, -0.50, 1,
    0.35, 0.35, -0.25, 1, 0.46, 0.19, -0.25, 1, 0.35, 0.35, -0.50, 1,
    0.35, 0.35, 0.50, 1, 0.35, 0.35, 0.25, 1, 0.19, 0.46, 0.25, 1,
    0.19, 0.46, 0.50, 1, 0.35, 0.35, 0.50, 1, 0.19, 0.46, 0.25, 1,
    0.35, 0.35, 0.25, 1, 0.35, 0.35, 0.00, 1, 0.19, 0.46, 0.00, 1,
    0.19, 0.46, 0.25, 1, 0.35, 0.35, 0.25, 1, 0.19, 0.46, 0.00, 1,
    0.35, 0.35, 0.00, 1, 0.35, 0.35, -0.25, 1, 0.19, 0.46, -0.25, 1,
    0.19, 0.46, 0.00, 1, 0.35, 0.35, 0.00, 1, 0.19, 0.46, -0.25, 1,
    0.35, 0.35, -0.25, 1, 0.35, 0.35, -0.50, 1, 0.19, 0.46, -0.50, 1,
    0.19, 0.46, -0.25, 1, 0.35, 0.35, -0.25, 1, 0.19, 0.46, -0.50, 1,
    0.19, 0.46, 0.50, 1, 0.19, 0.46, 0.25, 1, 0.00, 0.50, 0.25, 1,
    0.00, 0.50, 0.50, 1, 0.19, 0.46, 0.50, 1, 0.00, 0.50, 0.25, 1,
    0.19, 0.46, 0.25, 1, 0.19, 0.46, 0.00, 1, 0.00, 0.50, 0.00, 1,
    0.00, 0.50, 0.25, 1, 0.19, 0.46, 0.25, 1, 0.00, 0.50, 0.00, 1,
    0.19, 0.46, 0.00, 1, 0.19, 0.46, -0.25, 1, 0.00, 0.50, -0.25, 1,
    0.00, 0.50, 0.00, 1, 0.19, 0.46, 0.00, 1, 0.00, 0.50, -0.25, 1,
    0.19, 0.46, -0.25, 1, 0.19, 0.46, -0.50, 1, 0.00, 0.50, -0.50, 1,
    0.00, 0.50, -0.25, 1, 0.19, 0.46, -0.25, 1, 0.00, 0.50, -0.50, 1,
    0.00, 0.50, 0.50, 1, 0.00, 0.50, 0.25, 1, -0.19, 0.46, 0.25, 1,
    -0.19, 0.46, 0.50, 1, 0.00, 0.50, 0.50, 1, -0.19, 0.46, 0.25, 1,
    0.00, 0.50, 0.25, 1, 0.00, 0.50, 0.00, 1, -0.19, 0.46, 0.00, 1,
    -0.19, 0.46, 0.25, 1, 0.00, 0.50, 0.25, 1, -0.19, 0.46, 0.00, 1,
    0.00, 0.50, 0.00, 1, 0.00, 0.50, -0.25, 1, -0.19, 0.46, -0.25, 1,
    -0.19, 0.46, 0.00, 1, 0.00, 0.50, 0.00, 1, -0.19, 0.46, -0.25, 1,
    0.00, 0.50, -0.25, 1, 0.00, 0.50, -0.50, 1, -0.19, 0.46, -0.50, 1,
    -0.19, 0.46, -0.25, 1, 0.00, 0.50, -0.25, 1, -0.19, 0.46, -0.50, 1,
    -0.19, 0.46, 0.50, 1, -0.19, 0.46, 0.25, 1, -0.35, 0.35, 0.25, 1,
    -0.35, 0.35, 0.50, 1, -0.19, 0.46, 0.50, 1, -0.35, 0.35, 0.25, 1,
    -0.19, 0.46, 0.25, 1, -0.19, 0.46, 0.00, 1, -0.35, 0.35, 0.00, 1,
    -0.35, 0.35, 0.25, 1, -0.19, 0.46, 0.25, 1, -0.35, 0.35, 0.00, 1,
    -0.19, 0.46, 0.00, 1, -0.19, 0.46, -0.25, 1, -0.35, 0.35, -0.25, 1,
    -0.35, 0.35, 0.00, 1, -0.19, 0.46, 0.00, 1, -0.35, 0.35, -0.25, 1,
    -0.19, 0.46, -0.25, 1, -0.19, 0.46, -0.50, 1, -0.35, 0.35, -0.50, 1,
    -0.35, 0.35, -0.25, 1, -0.19, 0.46, -0.25, 1, -0.35, 0.35, -0.50, 1,
    -0.35, 0.35, 0.50, 1, -0.35, 0.35, 0.25, 1, -0.46, 0.19, 0.25, 1,
    -0.46, 0.19, 0.50, 1, -0.35, 0.35, 0.50, 1, -0.46, 0.19, 0.25, 1,
    -0.35, 0.35, 0.25, 1, -0.35, 0.35, 0.00, 1, -0.46, 0.19, 0.00, 1,
    -0.46, 0.19, 0.25, 1, -0.35, 0.35, 0.25, 1, -0.46, 0.19, 0.00, 1,
    -0.35, 0.35, 0.00, 1, -0.35, 0.35, -0.25, 1, -0.46, 0.19, -0.25, 1,
    -0.46, 0.19, 0.00, 1, -0.35, 0.35, 0.00, 1, -0.46, 0.19, -0.25, 1,
    -0.35, 0.35, -0.25, 1, -0.35, 0.35, -0.50, 1, -0.46, 0.19, -0.50, 1,
    -0.46, 0.19, -0.25, 1, -0.35, 0.35, -0.25, 1, -0.46, 0.19, -0.50, 1,
    -0.46, 0.19, 0.50, 1, -0.46, 0.19, 0.25, 1, -0.50, 0.00, 0.25, 1,
    -0.50, 0.00, 0.50, 1, -0.46, 0.19, 0.50, 1, -0.50, 0.00, 0.25, 1,
    -0.46, 0.19, 0.25, 1, -0.46, 0.19, 0.00, 1, -0.50, 0.00, 0.00, 1,
    -0.50, 0.00, 0.25, 1, -0.46, 0.19, 0.25, 1, -0.50, 0.00, 0.00, 1,
    -0.46, 0.19, 0.00, 1, -0.46, 0.19, -0.25, 1, -0.50, 0.00, -0.25, 1,
    -0.50, 0.00, 0.00, 1, -0.46, 0.19, 0.00, 1, -0.50, 0.00, -0.25, 1,
    -0.46, 0.19, -0.25, 1, -0.46, 0.19, -0.50, 1, -0.50, 0.00, -0.50, 1,
    -0.50, 0.00, -0.25, 1, -0.46, 0.19, -0.25, 1, -0.50, 0.00, -0.50, 1,
    -0.50, 0.00, 0.50, 1, -0.50, 0.00, 0.25, 1, -0.46, -0.19, 0.25, 1,
    -0.46, -0.19, 0.50, 1, -0.50, 0.00, 0.50, 1, -0.46, -0.19, 0.25, 1,
    -0.50, 0.00, 0.25, 1, -0.50, 0.00, 0.00, 1, -0.46, -0.19, 0.00, 1,
    -0.46, -0.19, 0.25, 1, -0.50, 0.00, 0.25, 1, -0.46, -0.19, 0.00, 1,
    -0.50, 0.00, 0.00, 1, -0.50, 0.00, -0.25, 1, -0.46, -0.19, -0.25, 1,
    -0.46, -0.19, 0.00, 1, -0.50, 0.00, 0.00, 1, -0.46, -0.19, -0.25, 1,
    -0.50, 0.00, -0.25, 1, -0.50, 0.00, -0.50, 1, -0.46, -0.19, -0.50, 1,
    -0.46, -0.19, -0.25, 1, -0.50, 0.00, -0.25, 1, -0.46, -0.19, -0.50, 1,
    -0.46, -0.19, 0.50, 1, -0.46, -0.19, 0.25, 1, -0.35, -0.35, 0.25, 1,
    -0.35, -0.35, 0.50, 1, -0.46, -0.19, 0.50, 1, -0.35, -0.35, 0.25, 1,
    -0.46, -0.19, 0.25, 1, -0.46, -0.19, 0.00, 1, -0.35, -0.35, 0.00, 1,
    -0.35, -0.35, 0.25, 1, -0.46, -0.19, 0.25, 1, -0.35, -0.35, 0.00, 1,
    -0.46, -0.19, 0.00, 1, -0.46, -0.19, -0.25, 1, -0.35, -0.35, -0.25, 1,
    -0.35, -0.35, 0.00, 1, -0.46, -0.19, 0.00, 1, -0.35, -0.35, -0.25, 1,
    -0.46, -0.19, -0.25, 1, -0.46, -0.19, -0.50, 1, -0.35, -0.35, -0.50, 1,
    -0.35, -0.35, -0.25, 1, -0.46, -0.19, -0.25, 1, -0.35, -0.35, -0.50, 1,
    -0.35, -0.35, 0.50, 1, -0.35, -0.35, 0.25, 1, -0.19, -0.46, 0.25, 1,
    -0.19, -0.46, 0.50, 1, -0.35, -0.35, 0.50, 1, -0.19, -0.46, 0.25, 1,
    -0.35, -0.35, 0.25, 1, -0.35, -0.35, 0.00, 1, -0.19, -0.46, 0.00, 1,
    -0.19, -0.46, 0.25, 1, -0.35, -0.35, 0.25, 1, -0.19, -0.46, 0.00, 1,
    -0.35, -0.35, 0.00, 1, -0.35, -0.35, -0.25, 1, -0.19, -0.46, -0.25, 1,
    -0.19, -0.46, 0.00, 1, -0.35, -0.35, 0.00, 1, -0.19, -0.46, -0.25, 1,
    -0.35, -0.35, -0.25, 1, -0.35, -0.35, -0.50, 1, -0.19, -0.46, -0.50, 1,
    -0.19, -0.46, -0.25, 1, -0.35, -0.35, -0.25, 1, -0.19, -0.46, -0.50, 1,
    -0.19, -0.46, 0.50, 1, -0.19, -0.46, 0.25, 1, -0.00, -0.50, 0.25, 1,
    -0.00, -0.50, 0.50, 1, -0.19, -0.46, 0.50, 1, -0.00, -0.50, 0.25, 1,
    -0.19, -0.46, 0.25, 1, -0.19, -0.46, 0.00, 1, -0.00, -0.50, 0.00, 1,
    -0.00, -0.50, 0.25, 1, -0.19, -0.46, 0.25, 1, -0.00, -0.50, 0.00, 1,
    -0.19, -0.46, 0.00, 1, -0.19, -0.46, -0.25, 1, -0.00, -0.50, -0.25, 1,
    -0.00, -0.50, 0.00, 1, -0.19, -0.46, 0.00, 1, -0.00, -0.50, -0.25, 1,
    -0.19, -0.46, -0.25, 1, -0.19, -0.46, -0.50, 1, -0.00, -0.50, -0.50, 1,
    -0.00, -0.50, -0.25, 1, -0.19, -0.46, -0.25, 1, -0.00, -0.50, -0.50, 1,
    -0.00, -0.50, 0.50, 1, -0.00, -0.50, 0.25, 1, 0.19, -0.46, 0.25, 1,
    0.19, -0.46, 0.50, 1, -0.00, -0.50, 0.50, 1, 0.19, -0.46, 0.25, 1,
    -0.00, -0.50, 0.25, 1, -0.00, -0.50, 0.00, 1, 0.19, -0.46, 0.00, 1,
    0.19, -0.46, 0.25, 1, -0.00, -0.50, 0.25, 1, 0.19, -0.46, 0.00, 1,
    -0.00, -0.50, 0.00, 1, -0.00, -0.50, -0.25, 1, 0.19, -0.46, -0.25, 1,
    0.19, -0.46, 0.00, 1, -0.00, -0.50, 0.00, 1, 0.19, -0.46, -0.25, 1,
    -0.00, -0.50, -0.25, 1, -0.00, -0.50, -0.50, 1, 0.19, -0.46, -0.50, 1,
    0.19, -0.46, -0.25, 1, -0.00, -0.50, -0.25, 1, 0.19, -0.46, -0.50, 1,
    0.19, -0.46, 0.50, 1, 0.19, -0.46, 0.25, 1, 0.35, -0.35, 0.25, 1,
    0.35, -0.35, 0.50, 1, 0.19, -0.46, 0.50, 1, 0.35, -0.35, 0.25, 1,
    0.19, -0.46, 0.25, 1, 0.19, -0.46, 0.00, 1, 0.35, -0.35, 0.00, 1,
    0.35, -0.35, 0.25, 1, 0.19, -0.46, 0.25, 1, 0.35, -0.35, 0.00, 1,
    0.19, -0.46, 0.00, 1, 0.19, -0.46, -0.25, 1, 0.35, -0.35, -0.25, 1,
    0.35, -0.35, 0.00, 1, 0.19, -0.46, 0.00, 1, 0.35, -0.35, -0.25, 1,
    0.19, -0.46, -0.25, 1, 0.19, -0.46, -0.50, 1, 0.35, -0.35, -0.50, 1,
    0.35, -0.35, -0.25, 1, 0.19, -0.46, -0.25, 1, 0.35, -0.35, -0.50, 1,
    0.35, -0.35, 0.50, 1, 0.35, -0.35, 0.25, 1, 0.46, -0.19, 0.25, 1,
    0.46, -0.19, 0.50, 1, 0.35, -0.35, 0.50, 1, 0.46, -0.19, 0.25, 1,
    0.35, -0.35, 0.25, 1, 0.35, -0.35, 0.00, 1, 0.46, -0.19, 0.00, 1,
    0.46, -0.19, 0.25, 1, 0.35, -0.35, 0.25, 1, 0.46, -0.19, 0.00, 1,
    0.35, -0.35, 0.00, 1, 0.35, -0.35, -0.25, 1, 0.46, -0.19, -0.25, 1,
    0.46, -0.19, 0.00, 1, 0.35, -0.35, 0.00, 1, 0.46, -0.19, -0.25, 1,
    0.35, -0.35, -0.25, 1, 0.35, -0.35, -0.50, 1, 0.46, -0.19, -0.50, 1,
    0.46, -0.19, -0.25, 1, 0.35, -0.35, -0.25, 1, 0.46, -0.19, -0.50, 1,
    0.46, -0.19, 0.50, 1, 0.46, -0.19, 0.25, 1, 0.50, 0.00, 0.25, 1,
    0.50, 0.00, 0.50, 1, 0.46, -0.19, 0.50, 1, 0.50, 0.00, 0.25, 1,
    0.46, -0.19, 0.25, 1, 0.46, -0.19, 0.00, 1, 0.50, 0.00, 0.00, 1,
    0.50, 0.00, 0.25, 1, 0.46, -0.19, 0.25, 1, 0.50, 0.00, 0.00, 1,
    0.46, -0.19, 0.00, 1, 0.46, -0.19, -0.25, 1, 0.50, 0.00, -0.25, 1,
    0.50, 0.00, 0.00, 1, 0.46, -0.19, 0.00, 1, 0.50, 0.00, -0.25, 1,
    0.46, -0.19, -0.25, 1, 0.46, -0.19, -0.50, 1, 0.50, 0.00, -0.50, 1,
    0.50, 0.00, -0.25, 1, 0.46, -0.19, -0.25, 1, 0.50, 0.00, -0.50, 1 };

    size_t dataSize = sizeof( GLfloat ) * getCylinderNumVert() * 4;

    GLfloat *vertPointer = malloc( dataSize );
    memcpy( vertPointer, verts, dataSize );

    return vertPointer;
}


// the average normal at each vertex
// this is just the outward x and y component the z component should not matter
// the z is the height component which would mess up the normal, it would angle it
// so it is not with respect to the surface but from the center as if it were a sphere
GLfloat* getCylinderNorms( void )
{
    GLfloat norms[] = {
    0.50, 0.00, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.46, 0.19, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.50, 0.00, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.46, 0.19, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.50, 0.00, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.46, 0.19, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.50, 0.00, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.46, 0.19, 0, 0, 0.50, 0.00, 0, 0, 0.46, 0.19, 0, 0,
    0.46, 0.19, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.35, 0.35, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.46, 0.19, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.35, 0.35, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.46, 0.19, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.35, 0.35, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.46, 0.19, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.35, 0.35, 0, 0, 0.46, 0.19, 0, 0, 0.35, 0.35, 0, 0,
    0.35, 0.35, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.19, 0.46, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.35, 0.35, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.19, 0.46, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.35, 0.35, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.19, 0.46, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.35, 0.35, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.19, 0.46, 0, 0, 0.35, 0.35, 0, 0, 0.19, 0.46, 0, 0,
    0.19, 0.46, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.00, 0.50, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.19, 0.46, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.00, 0.50, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.19, 0.46, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.00, 0.50, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.19, 0.46, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.00, 0.50, 0, 0, 0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0,
    0.00, 0.50, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    -0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    0.00, 0.50, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    -0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    0.00, 0.50, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    -0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    0.00, 0.50, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    -0.19, 0.46, 0, 0, 0.00, 0.50, 0, 0, -0.19, 0.46, 0, 0,
    -0.19, 0.46, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.35, 0.35, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.19, 0.46, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.35, 0.35, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.19, 0.46, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.35, 0.35, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.19, 0.46, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.35, 0.35, 0, 0, -0.19, 0.46, 0, 0, -0.35, 0.35, 0, 0,
    -0.35, 0.35, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.46, 0.19, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.35, 0.35, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.46, 0.19, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.35, 0.35, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.46, 0.19, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.35, 0.35, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.46, 0.19, 0, 0, -0.35, 0.35, 0, 0, -0.46, 0.19, 0, 0,
    -0.46, 0.19, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.50, 0.00, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.46, 0.19, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.50, 0.00, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.46, 0.19, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.50, 0.00, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.46, 0.19, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.50, 0.00, 0, 0, -0.46, 0.19, 0, 0, -0.50, 0.00, 0, 0,
    -0.50, 0.00, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.46, -0.19, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.50, 0.00, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.46, -0.19, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.50, 0.00, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.46, -0.19, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.50, 0.00, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.46, -0.19, 0, 0, -0.50, 0.00, 0, 0, -0.46, -0.19, 0, 0,
    -0.46, -0.19, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.35, -0.35, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.46, -0.19, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.35, -0.35, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.46, -0.19, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.35, -0.35, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.46, -0.19, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.35, -0.35, 0, 0, -0.46, -0.19, 0, 0, -0.35, -0.35, 0, 0,
    -0.35, -0.35, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.19, -0.46, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.35, -0.35, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.19, -0.46, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.35, -0.35, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.19, -0.46, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.35, -0.35, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.19, -0.46, 0, 0, -0.35, -0.35, 0, 0, -0.19, -0.46, 0, 0,
    -0.19, -0.46, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.00, -0.50, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.19, -0.46, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.00, -0.50, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.19, -0.46, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.00, -0.50, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.19, -0.46, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.00, -0.50, 0, 0, -0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0,
    -0.00, -0.50, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    -0.00, -0.50, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    -0.00, -0.50, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    -0.00, -0.50, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    0.19, -0.46, 0, 0, -0.00, -0.50, 0, 0, 0.19, -0.46, 0, 0,
    0.19, -0.46, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.35, -0.35, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.19, -0.46, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.35, -0.35, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.19, -0.46, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.35, -0.35, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.19, -0.46, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.35, -0.35, 0, 0, 0.19, -0.46, 0, 0, 0.35, -0.35, 0, 0,
    0.35, -0.35, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.46, -0.19, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.35, -0.35, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.46, -0.19, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.35, -0.35, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.46, -0.19, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.35, -0.35, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.46, -0.19, 0, 0, 0.35, -0.35, 0, 0, 0.46, -0.19, 0, 0,
    0.46, -0.19, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.50, 0.00, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.46, -0.19, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.50, 0.00, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.46, -0.19, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.50, 0.00, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.46, -0.19, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0,
    0.50, 0.00, 0, 0, 0.46, -0.19, 0, 0, 0.50, 0.00, 0, 0 };

    size_t dataSize = sizeof( GLfloat ) * getCylinderNumVert() * 4;

    GLfloat *normPointer = malloc( dataSize );
    memcpy( normPointer, norms, dataSize );

    return normPointer;
}

GLfloat* getCylinderUVs( void )
{

    GLfloat uvs[] = {
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0 };

    size_t dataSize = sizeof( GLfloat ) * getSquareNumVert() * 2;
    
    GLfloat *uvPointer = malloc( dataSize );
    memcpy( uvPointer, uvs, dataSize );

    return uvPointer;
}

// retunrns the number of verticies required for the cylinder sides
GLint getCylinderNumVert( void )
{
    // This is a constant value
    // it can be computed by the size of the array / size of a float
    // the problem is that is the size you get may be the size of a pointer
    
    return 384;
}


// Triangles are in order
// 0, 1 ,2 makes one triangle and 3 4 5 make the next and so on...
GLshort* getCylinderConnectData( void )
{
    GLuint numVerts = getCylinderNumVert();
    GLshort *connectData = malloc( sizeof( GLshort ) * numVerts );
    if( connectData == NULL )
    {
        perror( "could not malloc connect data for cylinder\n" );
        exit( 1 );
    }

    for( int i = 0; i < numVerts; i++ )
    {
        connectData[i] = i;
    }

    return connectData;
}
