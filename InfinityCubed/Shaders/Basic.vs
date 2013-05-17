layout(location = 0) in vec3 Location;
layout(location = 1) in vec3 InColor;
uniform mat4 Rotation;
uniform mat4 Perspective;
uniform vec2 Mouse;
out vec3 Color;
void main(void) {
	vec4 t = vec4(Location - 16, 1) * Rotation;
	gl_Position = vec4(t.xy, t.z - 32, t.w) * Perspective;
	Color = InColor;
}