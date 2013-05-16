#version 330
layout(location = 0) in vec3 Input;
uniform mat4 Rotation;
uniform mat4 Perspective;
out float Shade;
void main(void) {
	vec4 t = vec4(Input * 0.5, 1) * Rotation;
	gl_Position = vec4(t.xy, t.z - 2, t.w) * Perspective;
	Shade = -gl_Position.z * 0.3 + 1;
}