/*
 * Vector2.h
 *
 *  Created on: Dec 12, 2011
 *      Author: kyle
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_
#include <ostream>
#include <sstream>
#include <cmath>

class Vector2
{
public:
	//Members
	float x;
	float y;
	//Constructors
	Vector2();
	explicit Vector2(float const&newx, float const&newy);
	//Math
	//Vector3 by Vector3 Math
	Vector2		operator+(const Vector2& vector) const;
	Vector2		operator-(const Vector2& vector) const;
	Vector2		operator*(const Vector2& vector) const;
	Vector2		operator/(const Vector2& vector) const;
	Vector2&	operator+=(const Vector2& vector);
	Vector2&	operator-=(const Vector2& vector);
	Vector2&	operator*=(const Vector2& vector);
	Vector2&	operator/=(const Vector2& vector);
	//Vector3 by Float Math
	Vector2		operator-() const;
	Vector2		operator+(float const&num) const;
	Vector2		operator-(float const&num) const;
	Vector2		operator*(float const&num) const;
	Vector2		operator/(float const&num) const;
	Vector2&	operator+=(float const&num);
	Vector2&	operator-=(float const&num);
	Vector2&	operator*=(float const&num);
	Vector2&	operator/=(float const&num);
	//Boolean Equals Operators
	bool		operator==(const Vector2& vector) const;
	bool		operator!=(const Vector2& vector) const;
	//Static Predefines
	static const Vector2 Zero;
	static const Vector2 One;

	//Sets the Vector2 with zero values
	inline void zero() {
		x = 0.0f;
		y = 0.0f;
	}
	//Returns if the Vector2 is zero
	inline const bool isZero() {
		return (x*x + y*y) < (float)0.000001;//EPSILON
	}
	//Returns dot product
	inline const float dot(Vector2 const&vec) {
		return x*vec.x + y*vec.y;
	}

	//Returns distance between the Vector2's
	inline double dist(Vector2 const&vec) {
		return sqrt((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y));
	}

	//Returns squared distance between the Vector2's
	inline double distanceSquared(Vector2 const&vec) {
		return (x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y);
	}

};

//Constructors
inline Vector2::Vector2() {}
inline Vector2::Vector2(float const&x, float const&y) : x(x), y(y) {}

// Math
inline Vector2 Vector2::operator+(const Vector2& vector) const
{
	return Vector2(x + vector.x, y + vector.y);
}

inline Vector2 Vector2::operator-(const Vector2& vector) const
{
	return Vector2(x - vector.x, y - vector.y);
}
inline Vector2 Vector2::operator*(const Vector2& vector) const
{
	return Vector2(x * vector.x, y * vector.y);
}
inline Vector2 Vector2::operator/(const Vector2& vector) const
{
	return Vector2(x / vector.x, y / vector.y);
}
inline Vector2& Vector2::operator+=(const Vector2& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}
inline Vector2& Vector2::operator*=(const Vector2& vector)
{
	x *= vector.x;
	y *= vector.y;
	return *this;
}

inline Vector2& Vector2::operator/=(const Vector2& vector)
{
	x /= vector.x;
	y /= vector.y;
	return *this;
}

inline Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}
inline Vector2 Vector2::operator-(float const&num) const
{
	return Vector2(x - num, y - num);
}
inline Vector2 Vector2::operator+(float const&num) const
{
	return Vector2(x + num, y + num);
}
inline Vector2 Vector2::operator*(float const&num) const
{
	return Vector2(x * num, y * num);
}

inline Vector2 Vector2::operator/(float const&num) const
{
	return Vector2(x / num, y / num);
}
inline Vector2& Vector2::operator+=(const float& num)
{
	x += num;
	y += num;
	return *this;
}

inline Vector2& Vector2::operator-=(const float& num)
{
	x -= num;
	y -= num;
	return *this;
}
inline Vector2& Vector2::operator*=(const float& num)
{
	x *= num;
	y *= num;
	return *this;
}

inline Vector2& Vector2::operator/=(const float& num)
{
	x /= num;
	y /= num;
	return *this;
}
//Boolean
inline bool Vector2::operator==(const Vector2& vector) const
{
	return x == vector.x && y == vector.y;
}

inline bool Vector2::operator!=(const Vector2& vector) const
{
	return x != vector.x || y != vector.y;
}
//-----------------------------------------------------------------------------------
//Fast Static members
//-----------------------------------------------------------------------------

//Subtractes the two Vector2 objects
inline const Vector2 operator-(Vector2 const&lhs, Vector2 const&rhs) {
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}
//Adds the two Vector2 objects
inline const Vector2 operator+(Vector2 const&lhs, Vector2 const&rhs) {
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}
//divides the two Vector2 objects
inline const Vector2 operator/(Vector2 const&lhs, float const&rhs) {
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}
//Multiplies the two Vector2 objects
inline const Vector2 operator*(float lhs, Vector2 const &rhs) {
	Vector2 result;
	result.x = rhs.x * lhs;
	result.y = rhs.y * lhs;
	return result;
}
//Subtractes the two Vector2 objects
inline const Vector2& operator-=(Vector2 &lhs, const Vector2 &rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}
//Adds the two Vector2 objects
inline const Vector2& operator+=(Vector2 &lhs, const Vector2 &rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return  lhs;
}
//Divides the two Vector2 objects
inline const Vector2& operator/=(Vector2 &lhs, const Vector2 &rhs) {
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	return  lhs;
}
//Multiplies the two Vector2 objects
inline const Vector2& operator*=(Vector2 &lhs, const Vector2 &rhs) {
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	return  lhs;
}
//Multiplies the Vector2 object by a float
inline const Vector2& operator*=(Vector2 &lhs, const float &rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return  lhs;
}
//Compares the two Vector2 objects and returns (true) if they are not equal
inline const bool operator!=(Vector2 const&lhs, Vector2 const&rhs) {
	return (lhs.x != rhs.x) || (lhs.y != rhs.y);
}
//Compares the two Vector2 objects and returns (true) if they are equal
inline const bool operator==(Vector2 const&lhs, Vector2 const&rhs) {
	return ((lhs.x * rhs.x < (float)0.000001) && (lhs.y * rhs.y < (float)0.000001));
}




#endif /* VECTOR2_H_ */
