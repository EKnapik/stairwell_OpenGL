// object.c
// Author: Eric M. Knapik
// implemtation for ambiguous object

#include "object.h"



// the object creation method
Object* mkObject( ObjectType objectType )
{
    Object *newObject = malloc( sizeof( Object ) );
    if( newObject == NULL )
    {
        perror( "UNABLE TO MALLOC NEW OBJECT\n" );
        exit( 1 );
    }

    newObject->verticies = NULL;
    newObject->normals = NULL;
    newObject->connectivity = NULL;
    newObject->numVerts = 0;

    newObject->type = objectType;
    
    return newObject;
}

// the object deletion method
void destroyObject( Object *object )
{
    // This is basic cheching if the object exists then delete the
    // memory that was allocated for each place
    if( object != NULL )
    {
        // free each of my arrays that I might have allocated
        if( object->verticies != NULL )
        {
            free( object->verticies );
        }

        if( object->normals != NULL )
        {
            free( object->normals );
        }

        if( object->connectivity != NULL )
        {
            free( object->connectivity );
        }

        free( object );
    }

    return;
}

// can give an array of verticies for the object
void addVerticies( Object *object, GLfloat *verts, GLfloat *vertNorms,
                   GLshort *connections, GLuint numVerts )
{
    object->verticies = verts;
    object->normals = vertNorms;
    object->connectivity = connections;
    object->numVerts = numVerts;

    return;
}

// can add an individual triangle to the object mesh must be counter clockwise
void addTriangle( Object *object, GLfloat x1, GLfloat y1, GLfloat z1, 
                  GLfloat x2, GLfloat y2, GLfloat z2,
                  GLfloat x3, GLfloat y3, GLfloat z3 )
{
}

// given the connectivity data and the verticies
// will determine the normals of the verticies from the normal
// of the connecting faces
void findAverageNormals( Object *object )
{
}

// when ready setup the vBuffer and the eBuffer
void setupGLBuffers( Object *object )
{
    // 4 floats make up one vertex
    int dataSize = object->numVerts * 4 * sizeof( GLfloat );
    // 3 verticies make one triangle
    int elementDataSize = object->numVerts * 3 * sizeof( GLshort );

    // ask OpenGL to create on buffer object
    glGenBuffers( 1, &object->vBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, object->vBuffer );
    glBufferData( GL_ARRAY_BUFFER, dataSize*2, 0, GL_STATIC_DRAW );
    // This binds my normals and my verticies to the same buffer
    // my normals are also a vector 4
    glBufferSubData( GL_ARRAY_BUFFER, 0, dataSize, object->verticies );
    glBufferSubData( GL_ARRAY_BUFFER, dataSize, dataSize, object->normals );

    // now do the same for the element array
    glGenBuffers( 1, &object->eBuffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, object->eBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, elementDataSize, object->connectivity, GL_STATIC_DRAW );

    // unbind any buffer to the current array and element array
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void drawObject( Object *object )
{

    // bind the shader program to use
    glUseProgram( object->shaderProgram );

    // bind the array buffer
    glBindBuffer( GL_ARRAY_BUFFER, object->vBuffer );

    // bind the element array buffer
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, object->eBuffer );

    // enable my vertex
    // enable my normal
    // pass the vertex to the shader
    // pass other things to my shader

    // Everything ready for this object so draw it starting at 0 in the array
    glDrawElements( GL_TRIANGLES, object->numVerts, GL_UNSIGNED_SHORT, (void *)0 );

    return;
}


// END OF FILE //
