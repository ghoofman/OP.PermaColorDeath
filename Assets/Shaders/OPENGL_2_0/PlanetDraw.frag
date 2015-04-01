varying vec2 vUV; 

uniform vec4 uColor;
uniform sampler2D uColorTexture;

void main() {

	vec2 v = vec2(vUV.x, 1.0 - vUV.y);
	gl_FragColor = texture2D(uColorTexture, v);

	gl_FragColor *= uColor;
}
