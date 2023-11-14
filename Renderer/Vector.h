#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

template<class T>
class Vector3
{
public:
	T x, y, z, w;

	Vector3<T> operator+ (const Vector3<T>& other) const;
	Vector3<T> operator- (const Vector3<T>& other) const;
	Vector3<T> operator* (float Value) const;
	Vector3<T> operator/ (float Value) const;

	float static Magnitude(const Vector3<T>& vec);
	Vector3<T> static Normalize(const Vector3<T>& vec);
	float static Dot(const Vector3<T>& left, const Vector3<T>& right);
	float Dot(const Vector3<T>& other);
	Vector3<T> static Cross(const Vector3<T>& left, const Vector3<T>& right);
	Vector3<T> Cross(const Vector3<T>& other);
	Vector3(T fx, T fy, T fz, T fw);
	Vector3(T fx, T fy, T fz);
	void Print();
	//~Vector3();

private:

};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

template<class T>
Vector3<T>::Vector3(T fx, T fy, T fz, T fw)
{
	x = fx;
	y = fy;
	z = fz;
	w = fw;
}

template<class T>
Vector3<T>::Vector3(T fx, T fy, T fz)
{
	x = fx;
	y = fy;
	z = fz;
	w = 1;
}

template<class T>
Vector3<T> Vector3<T>::operator+ (const Vector3<T>& other) const
{
	Vector3<T> returnValue;
	returnValue.x = x + other.x;
	returnValue.y = y + other.y;
	returnValue.z = z + other.z;
	returnValue.w = w + other.w;
	return returnValue;
}

template<class T>
Vector3<T> Vector3<T>::operator- (const Vector3<T>& other) const
{
	Vector3<T> returnValue;
	returnValue.x = x + other.x;
	returnValue.y = y + other.y;
	returnValue.z = z + other.z;
	returnValue.w = w + other.w;
	return returnValue;
}

template<class T>
Vector3<T> Vector3<T>::operator* (const float value) const
{
	Vector3<T> returnValue = Vector3<T>(x * value, y * value, z * value);
	return returnValue;
}

template<class T>
Vector3<T> Vector3<T>::operator/ (const float value) const
{
	Vector3<T> returnValue = Vector3<T>(x / value, y / value, z / value);
	return returnValue;
}

template<class T>
float Vector3<T>::Magnitude(const Vector3<T>& vec)
{
	return sqrt(Dot(*this, *this));
}

template<class T>
Vector3<T> Vector3<T>::Normalize(const Vector3<T>& vec)
{
	return vec / Magnitude(vec);
}

template<class T>
float Vector3<T>::Dot(const Vector3<T>& left, const Vector3<T>& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

template<class T>
float Vector3<T>::Dot(const Vector3<T>& other)
{
	return x * other.x + y * other.y + z * other.z;
}

template<class T>
void Vector3<T>::Print()
{
	cout << "x:" << x << "  y:" << y << "  z:" << z << endl;
}


class Vector2
{
public:
	float x, y;

	Vector2(float u, float v) : x(u), y(v) {}
	void Print()
	{
		cout << "x:" << x << "  y:" << y << endl;
	}

	Vector2 operator +(const Vector2& value) const;
	Vector2 operator -(const Vector2& value) const;

	float static Dot(const Vector2& left, const Vector2& right);

	//Output is a vector(0,0,ax-by, ay-bx), so we only need to see the z result
	float static Cross(const Vector2& left, const Vector2& right);

	//~Vector2();

private:

};