#pragma once

template<class T>
class Vector3
{
public:
	T x, y, z, w;



	Vector3();
	~Vector3();

private:

};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

class Vector2
{
public:
	float x, y;

	Vector2(float u, float v) : x(u), y(v) {}
	~Vector2();

private:

};
