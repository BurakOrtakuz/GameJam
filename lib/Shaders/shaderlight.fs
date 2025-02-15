#version 330 core
out vec4 FragColor;

in vec2 worldPos;
in vec3 lightColor;

uniform vec2 lightPosition;
uniform float lightIntensity;

void main()
{
	float distance = length(worldPos.xy - lightPosition);
	float attenuation = smoothstep(0.0, 1.0, distance * lightIntensity);
	FragColor = vec4(lightColor, 1.0) * attenuation; // Yellow light
}