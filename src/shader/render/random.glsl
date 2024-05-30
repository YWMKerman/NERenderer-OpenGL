// random.glsl

uniform sampler2D randomSeed;

const uint LCG_A = uint(16807);
const uint LCG_C = uint(0);
const uint LCG_M = uint(2147483647);

uint seed;

void randomInit(vec2 screenOffset) {
    seed = uint(texture2D(randomSeed, screenOffset).x);
}

uint randomUint() {
    seed = (seed * LCG_A + LCG_C) % LCG_M;
    return seed;
}

float random01() {
    return float(randomUint() - uint(1)) / float(LCG_M - uint(1));
}

float random11() {
    return random01() * 2.0f - 1.0f;
}
