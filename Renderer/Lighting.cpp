#include "Lighting.h"

const Vector3f DirectionalLight::pos = Vector3f(0, 0, 0);
const Vector3f PointLight::rot = Vector3f(0, 0, 0);

Lighting::Lighting(Vector3f pos, Vector3f rot, float intensity)
	:position(pos), rotation(rot), intensity(intensity)
{
}

Lighting::~Lighting()
{
}


DirectionalLight::DirectionalLight(Vector3f rot, float intensity) : Lighting(DirectionalLight::pos, rot, intensity)
{
}

DirectionalLight::~DirectionalLight()
{
}

PointLight::PointLight(Vector3f pos, float intensity) : Lighting(pos, PointLight::rot, intensity)
{
}

PointLight::~PointLight()
{
}