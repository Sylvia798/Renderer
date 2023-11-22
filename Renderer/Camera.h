#pragma once
#include "Transform.h"
#include "Matrix.h"
#include "Vector.h"

typedef enum {Move, Rotate, Scale, None} CameraMovement_t;
class Camera
{
public:
	Transform transform;
	Vector3f LookAtPoint;
	Vector3f UpDirection;
	Matrix ViewMatrix;
	Matrix ProjectionMatrix;
	float ScaleSpeed;

	Camera();
	void SetCameraTransform(Vector3f position, Vector3f UpDirection, Vector3f LookAtDirection);
	//Matrix Perspective(float nearPlane, float farPlane, );
	void Orthographic(float nearPlane, float farPlane, Vector2 leftRightRange, Vector2 bottomUpRange);
	void Move(float x, float y);
	void Rotate(float horizontalAngle, float verticleAngle);
	void Scale(float value);
};