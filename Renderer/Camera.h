#pragma once
#include "Transform.h"
#include "Matrix.h"
#include "Vector.h"

class Camera
{
public:
	Transform transform;
	Matrix ViewMatrix;
	Matrix ProjectionMatrix;

	Camera();

	void SetCameraTransform(Vector3f position, Vector3f UpDirection, Vector3f LookAtDirection);
	//Matrix Perspective(float nearPlane, float farPlane, );
	void Orthographic(float nearPlane, float farPlane, Vector2 leftRightRange, Vector2 bottomUpRange);
};