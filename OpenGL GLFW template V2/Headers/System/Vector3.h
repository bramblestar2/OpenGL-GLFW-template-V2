#pragma once
namespace jf
{

	template <typename T>
	class Vector3
	{
	public:
		Vector3(T x, T y, T z)
			: x(x), y(y), z(z)
		{ }
		Vector3()
		{ x = 0; y = 0; z = 0; }

		T x;
		T y;
		T z;
	};

	template <typename T>
	Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
	{ return Vector3<T>(left.x + right.x, left.x + right.y, left.z + right.z); }

	template <typename T>
	Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
	{ return Vector3<T>(left.x - right.x, left.x - right.y, left.z - right.z); }

	template <typename T>
	Vector3<T> operator*(const Vector3<T>& left, const Vector3<T>& right)
	{ return Vector3<T>(left.x * right.x, left.x * right.y, left.z * right.z); }

	template <typename T>
	Vector3<T> operator/(const Vector3<T>& left, const Vector3<T>& right)
	{ return Vector3<T>(left.x / right.x, left.x / right.y, left.z / right.z); }

	template <typename T>
	Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right)
	{ return left + right; }

	template <typename T>
	Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right)
	{ return left - right; }

	template <typename T>
	Vector3<T>& operator*=(Vector3<T>& left, const Vector3<T>& right)
	{ return left * right; }

	template <typename T>
	Vector3<T>& operator/=(Vector3<T>& left, const Vector3<T>& right)
	{ return left / right; }

	template <typename T>
	bool operator==(const Vector3<T>& left, const Vector3<T>& right)
	{ return (left.x == right.x && left.y == right.y && left.z == right.z); }

	template <typename T>
	bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
	{ return (left.x != right.x && left.y != right.y && left.z != right.z); }

	typedef Vector3<float> Vector3f;
	typedef Vector3<unsigned int> Vector3u;
	typedef Vector3<int> Vector3i;
	typedef Vector3<double> Vector3d;

}