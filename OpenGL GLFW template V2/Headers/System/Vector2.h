#pragma once
namespace jf
{

	template <typename T>
	class Vector2
	{
	public:
		Vector2(T x, T y)
			: x(x), y(y)
		{ }
		Vector2()
		{ x = 0; y = 0; }

		T x;
		T y;
	};

	template <typename T>
	Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
	{ return Vector2<T>(left.x + right.x, left.x + right.y); }

	template <typename T>
	Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
	{ return Vector2<T>(left.x - right.x, left.x - right.y); }

	template <typename T>
	Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right)
	{ return Vector2<T>(left.x * right.x, left.x * right.y); }

	template <typename T>
	Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right)
	{ return Vector2<T>(left.x / right.x, left.x / right.y); }

	template <typename T>
	Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
	{ 
		left = left + right;
		return left; 
	}

	template <typename T>
	Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
	{
		left = left - right;
		return left;
	}

	template <typename T>
	Vector2<T>& operator*=(Vector2<T>& left, const Vector2<T>& right)
	{
		left = left * right;
		return left;
	}

	template <typename T>
	Vector2<T>& operator/=(Vector2<T>& left, const Vector2<T>& right)
	{
		left = left / right;
		return left;
	}

	template <typename T>
	bool operator==(const Vector2<T>& left, const Vector2<T>& right)
	{ return (left.x == right.x && left.y == right.y); }

	template <typename T>
	bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
	{ return (left.x != right.x && left.y != right.y); }

	typedef Vector2<float> Vector2f;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<int> Vector2i;
	typedef Vector2<double> Vector2d;

}