varying vec2 vUV; 
uniform vec3 uColor;

uniform sampler2D uColorTexture;

void main() {
	vec2 v = vec2(vUV.x, 1.0 - vUV.y);
	vec4 color = texture2D(uColorTexture, v);
	gl_FragColor = vec4(color.rgb * uColor, color.a);
}
