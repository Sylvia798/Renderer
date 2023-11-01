#include "Matrix.h"


Matrix Matrix::operator* (const Matrix& other) const
{
	
}

Matrix Matrix::operator* (float k) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			value[i][j] = value[i][j] * k;
		}
	}
}