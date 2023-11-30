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

class DirectionalLight : public Lighting
{
public:
	static const Vector3f pos;

	DirectionalLight(Vector3f rot, float intensity);
	~DirectionalLight();

private:
	
};


class PointLight : public Lighting
{
public:
	static const Vector3f rot;

	PointLight(Vector3f pos, float intensity);
	~PointLight();

private:

};