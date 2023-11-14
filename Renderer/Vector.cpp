#include "Vector.h"

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

float Vector2::Cross(const Vector2& left, const Vector2& right)
{
	return left.x * right.y - left.y * right.x;
}
