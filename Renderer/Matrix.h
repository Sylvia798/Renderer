#pragma once
#include <math.h>
#include "Vector.h"

static const float PI = 3.1415926535;

class Matrix
{
public:
	float value[4][4];
	float testValue;

	Matrix operator+ (const Matrix& other) const;
	Matrix operator* (const Matrix& other) const;
	Matrix operator* (float k) const;

	Matrix Translate(const Vector3f& value);
	Matrix RotateX(float angle);
	Matrix RotateY(float angle);
	Matrix RotateZ(float angle);
	Matrix Rotate(const Vector3f& value);
	Matrix Scale(const Vector3f& value);
	Matrix ObjectToWorld(Matrix& target);
	void Identity();
	Matrix();
	Matrix(const float (*initValue)[4]);
	//~Matrix();

private:

};