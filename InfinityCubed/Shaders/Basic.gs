#version 150
layout(points) in;
layout(points, max_vertices = 1) out;
in Data {
	vec3 Color;
} DataIn[1];
out Data {
	vec3 Color;
} DataOut;
void main() {
	gl_Position = gl_in[0].gl_Position;
	DataOut.Color = DataIn[0].Color;
	gl_PointSize = 3;
	EmitVertex();
}