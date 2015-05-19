// object.c
// Author: Eric M. Knapik
// implemtation for ambiguous object


#include "object.h"

/*
// Define the struct of my object
typedef struct Object_Struct
{
    GLfloat *verticies;
    GLfloat *normals;
    GLshort *connectivity;
    GLuint  numVerts;
    GLuint numConnect;

    GLuint textBufferID; //have to create a buffer to hold the image
    GLuint texCoordID; // the ID of the "texCoord" variable
    GLuint texID; // the id of the "texture" variable
    const char *texFile;

    GLuint  vBuffer;
    GLuint  eBuffer;
    Shader *shader;

} Object;
*/

// How to calculate a buffer offset into the vertex buffer
// this is so no warning occur because it expects a char *
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

// the object creation method
Object* mkObject( const char *texFile, const char *vert, const char *frag )
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

    newObject->shader = mkShader( vert, frag );

    newObject->texFile = texFile;
    
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

        destroyShader( object->shader );

        free( object );
    }

    return;
}

// can give an array of verticies for the object
void addVerticies( Object *object, GLfloat *verts, GLfloat *vertNorms,
                   GLshort *connections, GLuint numVerts, GLuint numConnect, GLfloat *uvs )
{
    object->verticies = verts;
    object->normals = vertNorms;
    object->connectivity = connections;
    object->numVerts = numVerts;
    object->numConnect = numConnect;
    object->uvs = uvs;

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
    int uvDataSize = object->numVerts * 2 * sizeof( GLfloat );
    // 3 verticies make one triangle
    int elementDataSize = object->numConnect * 3 * sizeof( GLshort );

    // ask OpenGL to create on buffer object
    glGenBuffers( 1, &object->vBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, object->vBuffer );
    glBufferData( GL_ARRAY_BUFFER, (dataSize*2) + uvDataSize, 0, GL_STATIC_DRAW );
    // This binds my normals and my verticies to the same buffer
    // my normals are also a vector 4
    glBufferSubData( GL_ARRAY_BUFFER, 0, dataSize, object->verticies );
    // loads in the normals
    glBufferSubData( GL_ARRAY_BUFFER, dataSize, dataSize, object->normals );
    // load in my uv coords
    glBufferSubData( GL_ARRAY_BUFFER, dataSize*2, uvDataSize, object->uvs );

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
    int dataSize = object->numVerts * 4 * sizeof( GLfloat );

    // bind the shader program to use
    glUseProgram( object->shader->shaderProgram );

    // bind the array buffer
    glBindBuffer( GL_ARRAY_BUFFER, object->vBuffer );

    // bind the element array buffer
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, object->eBuffer );

    // enable my vertex
    GLuint vPosition = glGetAttribLocation( object->shader->shaderProgram, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    // pass the vertex to the shader the offset is 0 because it is first
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

    // enable my normal
    GLuint vNormal = glGetAttribLocation( object->shader->shaderProgram, "vNormal" );
    glEnableVertexAttribArray( vNormal );
    // pass the normal to the shader, the offset is the data size of the vertex
    // the size of a normal is 4 floats, my step between is 0, and dont normalize this
    glVertexAttribPointer( vNormal, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(dataSize) );


    // TEXTURE STUFF
    // first load in the image
    glGenTextures( 1, &object->textBufferID );
    int width, height;
    unsigned char* image;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, object->textBufferID );
        image = SOIL_load_image( object->texFile, &width, &height, 0, SOIL_LOAD_RGB);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // pass the uv coords down
    object->texCoordID = glGetAttribLocation( object->shader->shaderProgram,
                        "s_vTexCoord" );
    glEnableVertexAttribArray( object->texCoordID );
    glVertexAttribPointer( object->texCoordID, 2, GL_FLOAT, GL_FALSE,
                           0, BUFFER_OFFSET(dataSize*2) );

    // actually pass the texture down
    glActiveTexture(GL_TEXTURE0);
    object->texID = glGetUniformLocation( object->shader->shaderProgram, "texture" );
    glUniform1i( object->texID, 0 );
    


    // pass other things to my shader using the function call
    shaderDisplay( object->shader );
    
    // Everything ready for this object so draw it starting at 0 in the array
    glDrawElements( GL_TRIANGLES, object->numVerts, GL_UNSIGNED_SHORT, (void *)0 );

    return;
}


// END OF FILE //
