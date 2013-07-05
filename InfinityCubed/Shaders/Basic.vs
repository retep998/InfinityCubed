#version 150

layout(location = 0) in vec3 Location;

uniform mat4 Rotation;
uniform mat4 Perspective;

out Data {
	vec3 Color;
} DataOut;

void main(void) {
	vec4 t = vec4(Location - 16, 1) * Rotation;
	gl_Position = vec4(t.xy, t.z - 32, t.w) * Perspective;
	DataOut.Color = Location / 32;
	gl_PointSize = 1;
}