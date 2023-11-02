#include "Matrix.h"



Matrix Matrix::operator+ (const Matrix& other) const
{
	Matrix returnValue;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			returnValue.value[i][j] += other.value[i][j];
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

Matrix Matrix::operator* (const Matrix& other) const
{
	Matrix returnValue;
	for (int i = 0; i < 4; i++) //Get matrixA line i
	{
		for (int j = 0; j < 4; j++) // Get matrixB column j
		{
			for (int k = 0; k < 4; k++)
			{
				returnValue.value[i][j] += value[i][k] * other.value[k][j];
			}
		}
	}
	return returnValue;
}