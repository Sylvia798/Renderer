#pragma once
#include "Vector.h"

class Matrix
{
public:
	float value[4][4];
	float testValue;

	Matrix operator+ (const Matrix& other) const;
	Matrix operator* (const Matrix& other) const;
	Matrix operator* (float k) const;
	//Matrix();
	//~Matrix();

private:

};