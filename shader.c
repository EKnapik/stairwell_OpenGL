// Author: Eric M. Knapik
//
// the shader object implementation file
// this refers to how the shader program to
// be executed depending on the object
// holds all the info for vertex and fragment shaders

/*
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
*/


// makes the a shader program with the default values
Shader* mkShader( const char *vert, const char *frag )
{
    Shader *shader = malloc( sizeof( Shader ) );
    if( shader == NULL )
    {
        perror( "could not malloc for shader object\n" );
        exit( 1 );
    }

    shader->shaderProgram = shaderSetup( vert, frag );
    // transformation matrix values
    shader->rotateVals = { 0.0f, 0.0f, 0.0f };
    shader->transVals = { 0.0f, 0.0f, 0.0f };
    shader->scaleVals = { 1.0f, 1.0f, 1.0f };

    // camera values
    shader->eyePos = { 0.0f, 0.0f, 1.0f };
    shader->lookAt = { 0.0f, 0.0f, -1.0f };
    shader->upVec = { 0.0f, 1.0f, 0.0f };

    // clipping window boundaries
    shader->left = -1.0f;
    shader->right = 1.0f;
    shader->top = 1.0f;
    shader->bot = -1.0f;
    shader->near = 1.0f;
    shader->far = 150.0f;

    return shader;
}

// destroys the shader
void destroyShader( Shader *shader)
{
    if( shader != NULL )
    {
        free( shader );
    }

    return;
}


// the method that sets up the shader program to be executed in the
// main display function
void shaderDisplay( Shader *shader );
{
    // pass the values for the frustum projection using the clipping values
    GLuint leftLoc = glGetUniformLocation( shader->shaderProgram, "left" );
    GLuint rightLoc = glGetUniformLocation( shader->shaderProgram, "right" );
    GLuint topLoc = glGetUniformLocation( shader->shaderProgram, "top" );
    GLuint bottomLoc = glGetUniformLocation( shader->shaderProgram, "bottom" );
    GLuint nearLoc = glGetUniformLocation( shader->shaderProgram, "near" );
    GLuint farLoc = glGetUniformLocation( shader->shaderProgram, "far" );

    glUniform1f( leftLoc, shader->left );
    glUniform1f( rightLoc, shader->right );
    glUniform1f( topLoc, shader->top );
    glUniform1f( bottomLoc, shader->bot );
    glUniform1f( nearLoc, shader->near );
    glUniform1f( farLoc, shader->far );

    // pass the values for the transformation matrix
    GLuint thetaLoc = glGetUniformLocation( shader->shaderProgram, "theta" );
    GLuint transLoc = glGetUniformLocation( shader->shaderProgram, "trans" );
    GLuint scaleLoc = glGetUniformLocation( shader->shaderProgram, "scale" );

    glUniform3fv( thetaLoc, 1, shader->rotateVals );
    glUniform3fv( transLoc, 1, shader->transVals );
    glUniform3fv( scaleLoc, 1, shader->scaleVals );

    // pass the values for the camera
    GLuint posLoc = glGetUniformLocation( shader->shaderProgram, "cPosition" ); 
    GLuint lookLoc = glGetUniformLocation( shader->shaderProgram, "cLookAt" );
    GLuint upVecLoc = glGetUniformLocation( shader->shaderProgram, "cUp" );

    glUniform3fv( posLoc, 1, shader->eyePos );
    glUniform3fv( lookLoc, 1, shader->lookAt );
    glUniform3fv( upVecLoc, 1, shader->upVec );

    // pass the values for the lighting calculations
    // the vertex and normals are being passed through the object
    // display function
    setUpLighting( shader );

    return;
}

// set camera to something other than default
void setCamera( Shader *shader, GLfloat eyePos[], GLfloat lookAt[], GLfloat upVec[] )
{
    shader->eyePos = eyePos;
    shader->lookAt = lookAt;
    shader->upVec = upVec;
    return;
}

// set rotatation values
// x, y, z
void setRotate( Shader *shader, GLfloat rotateVals[] )
{
    shader->rotateVals = rotateVals;
    return;
}


// set translation values
void setTrans( Shader *shader, GLfloat transVals[] )
{
    shader->transVals = transVals;
    return;
}

void setScale( Shader *shader, GLfloat scaleVals[] )
{
    shader->scaleVals = scaleVals;
    return;
}

void setUpLighting( Shader *shader )
{
    // get the locations of all my variables
    // in larger applications this should not be done every frame
    GLuint amColorLoc = glGetUniformLocation( shader->shaderProgram, "amColor" );
    GLuint amCoeffLoc = glGetUniformLocation( shader->shaderProgram, "amCoeff" );
    GLuint diffColorLoc = glGetUniformLocation( shader->shaderProgram, "diffColor" );
    GLuint diffCoeffLoc = glGetUniformLocation( shader->shaderProgram, "diffCoeff" );
    GLuint specColorLoc = glGetUniformLocation( shader->shaderProgram, "specColor" );
    GLuint specExpLoc = glGetUniformLocation( shader->shaderProgram, "specExp" );
    GLuint specCoeffLoc = glGetUniformLocation( shader->shaderProgram, "specCoeff" );
    GLuint lightColorLoc = glGetUniformLocation( shader->shaderProgram, "lightColor" );
    GLuint lightPosLoc = glGetUniformLocation( shader->shaderProgram, "lightPos" );
    GLuint amLightColorLoc = glGetUniformLocation( shader->shaderProgram, "amLightColor" );
 
    // set the values for my object color and light color
    // I believe the texture should replace the object color
    GLfloat amColor[] = {0.5, 0.1, 0.9, 1.0};
    GLfloat amCoeff = 0.5;
    GLfloat diffColor[] = {0.89, 0.0, 0.0, 1.0};
    GLfloat diffCoeff = 0.7;
    GLfloat specColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specExp = 10.0;
    GLfloat specCoeff = 1.0;
    GLfloat lightColor[] = {1.0, 1.0, 0.0, 1.0};
    GLfloat lightPos[] = {0.0, 5.0, 2.0, 1.0};
    GLfloat amLightColor[] = {0.5, 0.5, 0.5, 1.0};

    // pass the values to the shader by reference
    glUniform4fv( amColorLoc, 1, amColor );
    glUniform1f( amCoeffLoc, amCoeff );
    glUniform4fv( diffColorLoc, 1, diffColor );
    glUniform1f( diffCoeffLoc, diffCoeff );
    glUniform4fv( specColorLoc, 1, specColor );
    glUniform1f( specExpLoc, specExp );
    glUniform1f( specCoeffLoc, specCoeff );
    glUniform4fv( lightColorLoc, 1, lightColor );
    glUniform4fv( lightPosLoc, 1, lightPos );
    glUniform4fv( amLightColorLoc, 1, amLightColor );

    return;
}
