varying vec3 vNormal; 
varying vec3 vLightDirection;
uniform sampler2D uColorTexture; 
varying vec2 vTexCoord; 

void main() {

	vec2 uv = vec2(1.0 - vTexCoord.x, vTexCoord.y);

	vec3 LightColor = vec3(1,1,1);
	float LightPower = 0.2;
	
	vec3 MaterialDiffuseColor =  texture2D(uColorTexture, uv).rgb;
	vec3 MaterialAmbientColor = vec3(0.8,0.8,0.8) * MaterialDiffuseColor;
	
	vec3 n = normalize( vNormal );
	vec3 l = normalize( vLightDirection );
	float d = dot( n, l );
	float cosTheta = clamp( d, 0.0, 1.0 );
	
	gl_FragColor =
		vec4(
			MaterialAmbientColor +
			MaterialDiffuseColor * LightColor * LightPower * cosTheta, 
			1.0);
}
