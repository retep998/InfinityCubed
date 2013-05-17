layout(location = 0) out vec4 Output;
in vec3 Color;
void main(void) {
	Output = vec4(Color, 1);
}