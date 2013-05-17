#version 330
layout(location = 0) in vec3 Input;
uniform mat4 Rotation;
uniform mat4 Perspective;
uniform vec2 Mouse;
out vec3 Color;
void main(void) {
	vec4 t = vec4(Input * 0.6, 1) * Rotation;
	gl_Position = vec4(t.xy, t.z - 1.5, t.w) * Perspective;
	Color = vec3(Mouse.x, 1 - gl_Position.z * 0.5, Mouse.y);
}