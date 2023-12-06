#include "Lighting.h"
#include "Matrix.h"

const Vector3f DirectionalLight::pos = Vector3f(0, 0, 0);
const Vector3f PointLight::rot = Vector3f(0, 0, 0);

Lighting::Lighting(Vector3f pos, Vector3f rot, float intensity)
	:position(pos), rotation(rot), intensity(intensity)
{
}

Lighting::Lighting()
{

}

Lighting::~Lighting()
{
}


DirectionalLight::DirectionalLight(Vector3f rot, float intensity) : Lighting()
{
	Matrix rotMat;
	rotMat = rotMat.RotateX(rot.x).RotateY(rot.y).RotateZ(rot.z);
	Vector3f rotation = rotMat * Vector3f(0, 1, 0);
	Lighting::position = DirectionalLight::pos;
	Lighting::intensity = intensity;
	Lighting::rotation = rotation;
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