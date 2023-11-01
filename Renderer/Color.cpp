#include "Color.h"

Color::Color(float cr, float cg, float cb, float ca)
	:r(cr), g(cg), b(cb), a(ca)
{

}

Color::~Color()
{

}

Color Color::operator+ (const Color& other) const
{
	Color returnValue(r + other.r, g + other.g, b + other.b, a + other.a);
	return returnValue;
}
Color Color::operator+ (const float value) const
{
	Color returnValue(r + value, g + value, b + value, a);
	return returnValue;
}
Color Color::operator- (const Color& other) const
{
	Color returnValue(r - other.r, g - other.g, b - other.b, a - other.a);
	return returnValue;
}
Color Color::operator* (const Color& other) const
{
	Color returnValue(r * other.r, g * other.g, b * other.b, a * other.a);
	return returnValue;
}
Color Color::operator* (const float value) const
{
	Color returnValue(r * value, g * value, b * value, a * value);
	return returnValue;
}
Color Color::operator/ (const float value) const
{
	Color returnValue(r / value, g / value, b / value, a / value);
	return returnValue;
}
Color Color::Lerp(const Color& left, const Color& right, float lerpValue)
{
	return left * (1-lerpValue) + right * lerpValue;
}