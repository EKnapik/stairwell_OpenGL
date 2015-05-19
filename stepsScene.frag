#version 120

// Phong shading fragment shader
//  Edited by: Eric Knapik

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

// TEXTURE
varying vec2 texCoord;
uniform sampler2D texture;


void main()
{

    // LIGHTING CALUCLATIONS

    float LDN = max(dot( outLight, outNormal ), 0); //light dot normal

    vec4 reflectionVec = -(outLight - (2*LDN*outNormal));
    reflectionVec = normalize( reflectionVec );

    float RDV = max(dot(reflectionVec, outView), 0);

    //vec4 allAm = amCoeffOut * amLightColorOut * diffColorOut;
    //vec4 allDiff = diffCoeffOut * lightColorOut * diffColorOut * LDN;
    //vec4 allSpec = pow(RDV, specExpOut) * lightColorOut * specCoeffOut * specColorOut;
    vec4 allAm = amCoeffOut * amLightColorOut * texture2D(texture, texCoord);
    vec4 allDiff = diffCoeffOut * lightColorOut * texture2D(texture, texCoord) * LDN;
    vec4 allSpec = pow(RDV, specExpOut) * lightColorOut * specCoeffOut * texture2D(texture, texCoord);

    gl_FragColor = allAm + allDiff + allSpec;
}
