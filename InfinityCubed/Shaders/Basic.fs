#version 330
layout(location = 0) out vec4 Output;
in float Shade;
void main(void) {
	Output = vec4(0, Shade, 0, 1);
}