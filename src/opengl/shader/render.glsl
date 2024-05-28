#version 330 core

out vec4 outColor;

uniform sampler2D lastRenderResult;
uniform uvec2 screenGeometry;

void main() {
    outColor = vec4(1.0f * gl_FragCoord.x / screenGeometry.x,
                    1.0f * gl_FragCoord.y / screenGeometry.y,
                    1.0f,
                    1.0f);
}
