#version 330 core

out vec4 outColor;

uniform sampler2D lastRenderResult;
uniform uvec2 screenGeometry;

void main() {
    outColor = texture2D(lastRenderResult, gl_FragCoord.xy / screenGeometry);
}
