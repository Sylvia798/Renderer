#pragma once
#include <math.h>
#include "Vector.h"
#include "Matrix.h"

static const float PI = 3.1415926535f;

class Matrix
{
public:
	float value[4][4];

	Matrix operator+ (const Matrix& other) const;
	Matrix operator* (const Matrix& other) const;
	Vector3f operator* (const Vector3f& other) const;
	Vector2 operator* (const Vector2& other) const;
	Matrix operator* (float k) const;

	Matrix Translate(const Vector3f& value);
	Matrix RotateX(float angle);
	Matrix RotateY(float angle);
	Matrix RotateZ(float angle);
	Matrix Rotate(const Vector3f& value);
	Matrix Scale(const Vector3f& value);
	Vector3f ObjectToWorld(const Matrix& MVPMatrix, const Vector3f& target);
	void Identity();
	Matrix();
	Matrix(const float (*initValue)[4]);
	friend ostream& operator <<(ostream& os, const Matrix& value);

	//~Matrix();

private:

};