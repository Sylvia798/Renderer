#pragma once
#include "Vector.h"
class Color
{
public:
	float r, g, b, a;
	Color(float cr, float cg, float cb, float ca);
	Color(Vector3f col) :r(col.x), g(col.y), b(col.z), a(1.0) {}
	Color();
	~Color();

	Color operator+ (const Color& other) const;
	Color operator+ (const float value) const;
	Color operator- (const Color& other) const;
	Color operator* (const Color& other) const;
	Color operator* (const float value) const;
	Color operator/ (const float value) const;
	static Color Lerp(const Color& left, const Color& right, float lerpValue);
};