#version 150

layout(location = 0) out vec4 Output;

in Data {
	vec3 Color;
} DataIn;
void main(void) {
	Output = vec4(DataIn.Color, 1);
}