#pragma once
#include "Vector.h"
class Transform
{
public:
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;

	Transform() {}
	Transform(Vector3f pos, Vector3f rot, Vector3f sca) : position(pos), rotation(rot), scale(sca) {}

private:

};