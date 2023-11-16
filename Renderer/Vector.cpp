#include "Vector.h"
using namespace std;

Vector2 Vector2::operator +(const Vector2& value) const
{
	Vector2 returnValue(x + value.x, y + value.y);
	return returnValue;
}

Vector2 Vector2::operator -(const Vector2& value) const
{
	Vector2 returnValue(x - value.x, y - value.y);
	return returnValue;
}

Vector2 Vector2::operator *(float value) const
{
	Vector2 returnValue(x * value, y * value);
	return returnValue;
}

float Vector2::Cross(const Vector2& left, const Vector2& right)
{
	return left.x * right.y - left.y * right.x;
}

ostream& operator << (ostream& os, const Vector2& value)
{
	os << '(' << value.x << ", " << value.y << ")";
	return os;
}

float Vector2::operator[](int index) const
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	default:
		throw out_of_range("Vector2 index out of range");
		break;
	}
}

float Vector2::operator[](int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	default:
		throw out_of_range("Vector2 index out of range");
		break;
	}
}
