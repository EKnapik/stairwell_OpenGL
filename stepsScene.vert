#version 120

// Phong shading vertex shader for cylinder
//  Edited by: Eric Knapik

// INCOMING DATA

// Vertex location (in model space)
attribute vec4 vPosition;

// Normal vector at vertex (in model space)
attribute vec4 vNormal;

// TEXTURE
attribute vec2 s_vTexCoord;
varying vec2 texCoord;

// Model transformations
uniform vec3 theta;
uniform vec3 trans;
uniform vec3 scale;

// Camera parameters
uniform vec3 cPosition;
uniform vec3 cLookAt;
uniform vec3 cUp;

// View volume boundaries
uniform float left;
uniform float right;
uniform float top;
uniform float bottom;
uniform float near;
uniform float far;

// Lighting variables
uniform vec4 ambientColor;
uniform float amCoeff;
uniform vec4 diffColor;
uniform float diffCoeff;
uniform vec4 specColor;
uniform float specExp;
uniform float specCoeff;
uniform vec4 lightColor;
uniform vec4 lightPos;
uniform vec4 amLightColor;

// OUTGOING DATA
varying vec4 outLight;
varying vec4 outNormal;
varying vec4 outView;

// OUT Lighting variables
varying vec4 amColorOut;
varying float amCoeffOut;
varying vec4 diffColorOut;
varying float diffCoeffOut;
varying vec4 specColorOut;
varying float specExpOut;
varying float specCoeffOut;
varying vec4 lightColorOut;
varying vec4 amLightColorOut;

void main()
{
    // Compute the sines and cosines of each rotation about each axis
    vec3 angles = radians( theta );
    vec3 c = cos( angles );
    vec3 s = sin( angles );

    // Create rotation matrices
    mat4 rxMat = mat4( 1.0,  0.0,  0.0,  0.0,
                       0.0,  c.x,  s.x,  0.0,
                       0.0,  -s.x, c.x,  0.0,
                       0.0,  0.0,  0.0,  1.0 );

    mat4 ryMat = mat4( c.y,  0.0,  -s.y, 0.0,
                       0.0,  1.0,  0.0,  0.0,
                       s.y,  0.0,  c.y,  0.0,
                       0.0,  0.0,  0.0,  1.0 );

    mat4 rzMat = mat4( c.z,  s.z,  0.0,  0.0,
                       -s.z, c.z,  0.0,  0.0,
                       0.0,  0.0,  1.0,  0.0,
                       0.0,  0.0,  0.0,  1.0 );

    mat4 xlateMat = mat4( 1.0,     0.0,     0.0,     0.0,
                          0.0,     1.0,     0.0,     0.0,
                          0.0,     0.0,     1.0,     0.0,
                          trans.x, trans.y, trans.z, 1.0 );

    mat4 scaleMat = mat4( scale.x,  0.0,     0.0,     0.0,
                          0.0,      scale.y, 0.0,     0.0,
                          0.0,      0.0,     scale.z, 0.0,
                          0.0,      0.0,     0.0,     1.0 );

    // Create view matrix
    vec3 nVec = normalize( cPosition - cLookAt );
    vec3 uVec = normalize( cross (normalize(cUp), nVec) );
    vec3 vVec = normalize( cross (nVec, uVec) );

    mat4 viewMat = mat4( uVec.x, vVec.x, nVec.x, 0.0,
                         uVec.y, vVec.y, nVec.y, 0.0,
                         uVec.z, vVec.z, nVec.z, 0.0,
                         -1.0*(dot(uVec, cPosition)),
                         -1.0*(dot(vVec, cPosition)),
                         -1.0*(dot(nVec, cPosition)), 1.0 );

    // Create projection matrix
    mat4 projMat = mat4( (2.0*near)/(right-left), 0.0, 0.0, 0.0,
                         0.0, ((2.0*near)/(top-bottom)), 0.0, 0.0,
                         ((right+left)/(right-left)),
                         ((top+bottom)/(top-bottom)),
                         ((-1.0*(far+near)) / (far-near)), -1.0,
                         0.0, 0.0, ((-2.0*far*near)/(far-near)), 0.0 );

    // Transformation order:
    //    scale, rotate Z, rotate Y, rotate X, translate
    mat4 modelMat = xlateMat * rxMat * ryMat * rzMat * scaleMat;
    mat4 modelViewMat = viewMat * modelMat;

    // Transform the vertex location into clip space
    gl_Position =  projMat * viewMat  * modelMat * vPosition;

    // LIGHTING CALCULATIONS
    outLight = viewMat * lightPos;
    outLight = outLight - (modelMat * viewMat * vPosition);
    outLight = normalize( outLight );

    outNormal = vNormal;
    outNormal = viewMat * modelMat * outNormal;
    outNormal = normalize( outNormal );

    outView = viewMat * vec4(cPosition, 1.0);
    outView = outView - (modelViewMat * vPosition);
    outView = normalize( outView );

    amColorOut = ambientColor;
    amCoeffOut = amCoeff;
    diffColorOut = diffColor;
    diffCoeffOut = diffCoeff;
    specColorOut = specColor;
    specExpOut = specExp;
    specCoeffOut = specCoeff;
    lightColorOut = lightColor;
    amLightColorOut = amLightColor;

    // Pass the texture through
    texCoord = s_vTexCoord;
}
