#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>
#include <stdexcept>

using namespace std;

template<class T>
class Vector3
{
public:
	T x, y, z, w;

	Vector3<T> operator+ (const Vector3<T>& other) const;
	Vector3<T> operator- (const Vector3<T>& other) const;
	Vector3<T> operator- () const;
	Vector3<T> operator* (float Value) const;
	Vector3<T> operator/ (float Value) const;
	const T& operator[](int index) const
	{
		switch (index)
		{
		case 0: return x;
		case 1:return y;
		case 2:return z;
		case 3:return w;
		default:
			throw out_of_range("Vector3 index out of range");
			break;
		}
	}

	T& operator[](int index)
	{
		switch (index)
		{
		case 0: return x;
		case 1:return y;
		case 2:return z;
		case 3:return w;
		default:
			throw out_of_range("Vector3 index out of range");
			break;
		}
	}

	float static Magnitude(const Vector3<T>& vec);
	Vector3<T> static Normalize(const Vector3<T>& vec);
	void Normalize();
	float static Dot(const Vector3<T>& left, const Vector3<T>& right);
	float Dot(const Vector3<T>& other);
	Vector3<T> static Cross(const Vector3<T>& left, const Vector3<T>& right);
	Vector3(T fx, T fy, T fz, T fw);
	Vector3(T fx, T fy, T fz);
	Vector3();
	void Print();

	template<typename U>
	friend ostream& operator<< (ostream& os, const Vector3<U>& value);
	//~Vector3();

private:

};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

template<class T>
Vector3<T>::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

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
	returnValue.x = x - other.x;
	returnValue.y = y - other.y;
	returnValue.z = z - other.z;
	returnValue.w = w - other.w;
	return returnValue;
}

template<class T>
Vector3<T> Vector3<T>::operator- () const
{
	Vector3<T> returnValue;
	returnValue.x = -x;
	returnValue.y = -y;
	returnValue.z = -z;
	returnValue.w = -w;
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
	return sqrt(Dot(vec, vec));
}

template<class T>
Vector3<T> Vector3<T>::Normalize(const Vector3<T>& vec)
{
	return vec / Magnitude(vec);
}

template<class T>
void Vector3<T>::Normalize()
{
	*this = *this / Magnitude(*this);
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
Vector3<T> Vector3<T>::Cross(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3(
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

template<class T>
void Vector3<T>::Print()
{
	cout << "x:" << x << "  y:" << y << "  z:" << z << endl;
}

template<typename U>
ostream& operator<< (ostream& os, const Vector3<U>& value) 
{
	os << "(" << value.x << ", " << value.y << ", " << value.z << ")";
	return os;
}


class Vector2
{
public:
	float x, y;

	Vector2(float u, float v) : x(u), y(v) {}
	Vector2() : x(0), y(0) {}
	void Print()
	{
		cout << "x:" << x << "  y:" << y << endl;
	}

	Vector2 operator +(const Vector2& value) const;
	Vector2 operator -(const Vector2& value) const;
	Vector2 operator *(float value) const;
	friend ostream& operator <<(ostream& os, const Vector2& value);
	float operator[](int index) const;
	float operator[](int index);

	float static Dot(const Vector2& left, const Vector2& right);

	//Output is a vector(0,0,ax-by, ay-bx), so we only need to see the z result
	float static Cross(const Vector2& left, const Vector2& right);

	//~Vector2();

private:

};