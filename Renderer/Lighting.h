#pragma once
#include "Vector.h"

class Lighting
{
public:
	Vector3f position;
	Vector3f rotation;
	float intensity;

	Lighting(Vector3f pos, Vector3f rot, float intensity);
	~Lighting();

private:

};

Lighting::Lighting(Vector3f pos, Vector3f rot, float intensity)
	:position(pos), rotation(rot), intensity(intensity)
{
}

Lighting::~Lighting()
{
}


class DirectionalLight : public Lighting
{
public:
	static const Vector3f pos;

	DirectionalLight(Vector3f rot, float intensity);
	~DirectionalLight();

private:
	
};

const Vector3f DirectionalLight::pos = Vector3f(0, 0, 0);

DirectionalLight::DirectionalLight(Vector3f rot, float intensity) : Lighting(DirectionalLight::pos, rot, intensity)
{
}

DirectionalLight::~DirectionalLight()
{
}

class PointLight : public Lighting
{
public:
	static const Vector3f rot;

	PointLight(Vector3f pos, float intensity);
	~PointLight();

private:

};

const Vector3f PointLight::rot = Vector3f(0, 0, 0);

PointLight::PointLight(Vector3f pos, float intensity) : Lighting(pos, PointLight::rot, intensity)
{
}

PointLight::~PointLight()
{
}