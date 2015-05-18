// square.h
// Author: Eric M. Knapik
// header file

#include "square.h"

GLfloat* getSquareVerticies( void )
{
    GLfloat verts[] = {

};

    size_t dataSize = sizeof( GLfloat ) * getSquareNumVert() * 4;

    GLfloat *vertPointer = malloc( dataSize );
    memcpy( vertPointer, verts, dataSize );

    return vertPointer;
}

GLfloat* getSquareNorms( void )
{
    GLfloat norms[] = {


};

    size_t dataSize = sizeof( GLfloat ) * getSquareNumVert() * 4;
    
    GLfloat *normPointer = malloc( dataSize );
    memcpy( normPointer, norms, dataSize );

    return normPointer;
}

GLint getSquareNumVert( void )
{
    return 00;
}

GLshort* getSquareConnectData( void )
{
    GLuint numVerts = getSquareNumVert();
    GLshort *connectData = malloc( sizeof( GLshort ) * numVerts );
    if( connectData == NULL )
    {
        perror( "could not malloc connect data for square\n" );
        exit( 1 );
    }

    for( int i = 0; i < numVerts; i++ )
    {
        connectData[i] = i;
    }

    return connectData;
}
