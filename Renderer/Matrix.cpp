#include "Matrix.h"

Matrix::Matrix()
{
	Identity();
}

Matrix::Matrix(const float (*initValue)[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			value[i][j] = initValue[i][j];
		}
	}
}

void Matrix::Identity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) value[i][j] = 1;
			else value[i][j] = 0;
		}
	}
}

Matrix Matrix::operator+ (const Matrix& other) const
{
	Matrix returnValue;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			returnValue.value[i][j] = other.value[i][j];
		}
	}
	return returnValue;
}

Matrix Matrix::operator* (float k) const
{
	Matrix returnValue;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			returnValue.value[i][j] = value[i][j] * k;
		}
	}
	return returnValue;
}

Matrix Matrix::operator* (const Matrix& rightMatrix) const
{
	Matrix returnValue;
	for (int i = 0; i < 4; i++) //Get matrixA line i
	{
		for (int j = 0; j < 4; j++) // Get matrixB column j
		{
			returnValue.value[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				returnValue.value[i][j] += value[i][k] * rightMatrix.value[k][j];
			}
		}
	}
	return returnValue;
}

Vector3f Matrix::operator* (const Vector3f& vector) const
{
	Vector3f returnValue;
	for (int i = 0; i < 4; i++) //Get matrixA line i
	{
		for (int j = 0; j < 4; j++) // Get matrixB column j
		{
			if(i == 0) returnValue.x += value[i][j] * vector.x;
			if(i == 1) returnValue.y += value[i][j] * vector.y;
			if(i == 2) returnValue.z += value[i][j] * vector.z;
		}
	}
	return returnValue;
}

Vector2 Matrix::operator* (const Vector2& vector) const
{
	Vector2 returnValue;
	for (int i = 0; i < 4; i++) //Get matrixA line i
	{
		for (int j = 0; j < 4; j++) // Get matrixB column j
		{
			if(i == 0) returnValue.x += value[i][j] * vector.x;
			if(i == 1) returnValue.y += value[i][j] * vector.y;
		}
	}
	return returnValue;
}

ostream& operator << (ostream& os, const Matrix& value)
{
	os << "Matrix" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			os << value.value[i][j] << ", ";
		}
		os << endl;
	}
	return os;
}

Matrix Matrix::Translate(const Vector3f& value)
{
	Matrix returnValue;
	returnValue.value[0][3] = value.x;
	returnValue.value[1][3] = value.y;
	returnValue.value[2][3] = value.z;
	return returnValue * (*this);
}

Matrix Matrix::RotateX(float angle)
{
	Matrix returnValue;
	float radian = angle * PI / 180;
	returnValue.value[1][1] = cos(radian);
	returnValue.value[2][1] = sin(radian);
	returnValue.value[1][2] = -sin(radian);
	returnValue.value[2][2] = cos(radian);
	return returnValue * (*this);
}

Matrix Matrix::RotateY(float angle)
{
	Matrix returnValue;
	float radian = angle * PI / 180;
	returnValue.value[0][0] = cos(radian);
	returnValue.value[2][0] = -sin(radian);
	returnValue.value[0][2] = sin(radian);
	returnValue.value[2][2] = cos(radian);
	return returnValue * (*this);
}

Matrix Matrix::RotateZ(float angle)
{
	Matrix returnValue;
	float radian = angle * PI / 180;
	returnValue.value[0][0] = cos(radian);
	returnValue.value[1][0] = sin(radian);
	returnValue.value[0][1] = -sin(radian);
	returnValue.value[1][1] = cos(radian);
	return returnValue * (*this);
}

Matrix Matrix::Rotate(const Vector3f& value)
{
	Matrix returnValue;
	returnValue = returnValue.RotateX(value.x).RotateY(value.y).RotateZ(value.z);
	return returnValue * (*this);
}

Matrix Matrix::Scale(const Vector3f& value)
{
	Matrix returnValue;
	returnValue.value[0][0] = value.x;
	returnValue.value[1][1] = value.y;
	returnValue.value[2][2] = value.z;
	return returnValue * (*this);
}

Vector3f Matrix::ObjectToWorld(const Matrix& MVPMatrix, const Vector3f& target)
{
	Vector3f returnValue(target);
	returnValue = MVPMatrix * target;
	return returnValue;
}

