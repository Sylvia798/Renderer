#include "Camera.h"

Camera::Camera()
{
	ScaleSpeed = 1.1;
	LookAtPoint = Vector3f(0, 0, -1);
	UpDirection = Vector3f(0, 1, 0);
}

void Camera::SetCameraTransform(Vector3f position, Vector3f UpDirection, Vector3f LookAtPoint)
{
	this->LookAtPoint = LookAtPoint;
	this->UpDirection = UpDirection;
	Vector3f LookAtVector(LookAtPoint);
	Vector3f RightVector = Vector3f::Cross(UpDirection, LookAtVector);

	RightVector.Normalize();
	UpDirection.Normalize();
	LookAtVector.Normalize();

	Matrix RotateMatrix;
	RotateMatrix.value[0][0] = RightVector[0]; RotateMatrix.value[0][1] = UpDirection[0]; RotateMatrix.value[0][2] = LookAtVector[0];
	RotateMatrix.value[1][0] = RightVector[1]; RotateMatrix.value[1][1] = UpDirection[1]; RotateMatrix.value[1][2] = LookAtVector[1];
	RotateMatrix.value[2][0] = RightVector[2]; RotateMatrix.value[2][1] = UpDirection[2]; RotateMatrix.value[2][2] = LookAtVector[2];
	
	RotateMatrix = RotateMatrix.Inverse();

	Matrix newViewMatrix(RotateMatrix.Translate(-position));
	ViewMatrix = newViewMatrix;
}

void Camera::Orthographic(float nearPlane, float farPlane, Vector2 leftRightRange, Vector2 bottomUpRange)
{
	Matrix returnValue;
	returnValue = returnValue.Translate(Vector3f(-(leftRightRange.x + leftRightRange.y) / 2, -(bottomUpRange.x + bottomUpRange.y) / 2, -(nearPlane + farPlane) / 2));
	returnValue = returnValue.Scale(Vector3f(2 / (leftRightRange.y - leftRightRange.x), 2 / (bottomUpRange.y - bottomUpRange.x), 2 / (farPlane - nearPlane)));
	ProjectionMatrix = returnValue;
}

void Camera::Move(float x, float y)
{

}

void Camera::Rotate(float horizontalAngle, float verticleAngle)
{

}

void Camera::Scale(float value)
{
	Vector3f ScaleDirection = Vector3f::Normalize(LookAtPoint);
	transform.position = transform.position + ScaleDirection * value * ScaleSpeed;
	SetCameraTransform(transform.position, UpDirection, LookAtPoint);
	Vector3f scaleSize(value * ScaleSpeed, value * ScaleSpeed, 1);
	ProjectionMatrix = ProjectionMatrix.Scale(scaleSize);
}