varying vec3 vNormal; 
varying vec3 vLightDirection;
uniform vec3 uColor;

void main() {

	vec3 LightColor = vec3(1,1,1);
	float LightPower = 0.2;
	
	vec3 MaterialAmbientColor = uColor * 0.8;
	
	vec3 n = normalize( vNormal );
	vec3 l = normalize( vLightDirection );
	float d = dot( n, l );
	float cosTheta = clamp( d, 0.0, 1.0 );
	
	gl_FragColor = 
		vec4(
			MaterialAmbientColor +
			MaterialAmbientColor * LightColor * LightPower * cosTheta, 
			1.0);
}
