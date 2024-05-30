// main.glsl

void main() {
    outColor = vec4(1.0f * gl_FragCoord.x / screenGeometry.x,
                    1.0f * gl_FragCoord.y / screenGeometry.y,
                    1.0f,
                    1.0f);
}
