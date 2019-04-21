/*
 * Vector3.h
 *
 *  Created on: Dec 4, 2011
 *      Author: kyle J
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <ostream>
#include <sstream>
#include <cmath>
#include <cfloat>
 //#include "const.h"

class Vector3
{
public:
	//Members
	float x;
	float y;
	float z;
	//Constructors
	Vector3();
	explicit Vector3(float const&x, float const&y, float const&z);
	//Vector3 by Vector3 Math
	Vector3		operator+(const Vector3& vector) const;
	Vector3		operator-(const Vector3& vector) const;
	Vector3		operator*(const Vector3& vector) const;
	Vector3		operator/(const Vector3& vector) const;
	Vector3&	operator+=(const Vector3& vector);
	Vector3&	operator-=(const Vector3& vector);
	Vector3&	operator*=(const Vector3& vector);
	Vector3&	operator/=(const Vector3& vector);
	//Vector3 by Float Math
	Vector3		operator-() const;
	Vector3		operator+(float const&num) const;
	Vector3		operator-(float const&num) const;
	Vector3		operator*(float const&num) const;
	Vector3		operator/(float const&num) const;
	Vector3&	operator+=(float const&num);
	Vector3&	operator-=(float const&num);
	Vector3&	operator*=(float const&num);
	Vector3&	operator/=(float const&num);
	//Boolean Equals Operators
	bool		operator==(const Vector3& vector) const;
	bool		operator!=(const Vector3& vector) const;
	//Static Predefines
	static const Vector3 zero;
	static const Vector3 Left;
	static const Vector3 Right;
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Forward;
	static const Vector3 Backward;

	//-----------------------------------------------------------------------------------
	//Fast non-member functions
	//-----------------------------------------------------------------------------

	//Returns (Float) dot product of the two Vector3 objects
	inline float dot(Vector3 const&vec) {
		return x*vec.x + y*vec.y + z*vec.z;
	}
	//Returns (Float) length squared of the Vector3 object
	inline float lengthSquared() {
		return dot(*this);
	}
	//Returns (Float) magnitude (length) of the Vector3 object
	inline float magnitude() {
		return sqrt(dot(*this));
	}
	//Returns (Float) distance squared between the two Vector3 objects
	inline float distanceSquared(Vector3 const&vec) {
		return (x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z);
	}
	//Returns (Float) distance between the two Vector3 objects
	inline float distance(Vector3 const&vec) {
		return sqrt((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z));
	}

	//Voids
	inline void setMagnitude(float const&num)
	{
		*this *= num / magnitude();
	}
	//Sets
	inline void setLengthSquared(float const&num)
	{
		float vecLength = lengthSquared();

		if (vecLength == 0)
		{
			return;
		}
		*this *= num / sqrt(vecLength);
	}
	//Sets (Vector3) values of the Vector3 object to zero
	inline void tozero() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	//Returns (Boolean) True if the Vector3 object is zero else False
	inline const bool iszero() {
		return (x*x + y*y + z*z) < (float)0.000001;//EPSILON
	}
};

//Constructors
inline Vector3::Vector3() {}
inline Vector3::Vector3(float const&x, float const&y, float const&z) : x(x), y(y), z(z) {}

// Math
inline Vector3 Vector3::operator+(const Vector3& vector) const
{
	return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

inline Vector3 Vector3::operator-(const Vector3& vector) const
{
	return Vector3(x - vector.x, y - vector.y, z - vector.z);
}
inline Vector3 Vector3::operator*(const Vector3& vector) const
{
	return Vector3(x * vector.x, y * vector.y, z * vector.z);
}
inline Vector3 Vector3::operator/(const Vector3& vector) const
{
	return Vector3(x / vector.x, y / vector.y, z / vector.z);
}
inline Vector3& Vector3::operator+=(const Vector3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}
inline Vector3& Vector3::operator*=(const Vector3& vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	return *this;
}

inline Vector3& Vector3::operator/=(const Vector3& vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	return *this;
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}
inline Vector3 Vector3::operator-(float const&num) const
{
	return Vector3(x - num, y - num, z - num);
}
inline Vector3 Vector3::operator+(float const&num) const
{
	return Vector3(x + num, y + num, z + num);
}
inline Vector3 Vector3::operator*(float const&num) const
{
	return Vector3(x * num, y * num, z * num);
}

inline Vector3 Vector3::operator/(float const&num) const
{
	return Vector3(x / num, y / num, z / num);
}
inline Vector3& Vector3::operator+=(const float& num)
{
	x += num;
	y += num;
	z += num;
	return *this;
}

inline Vector3& Vector3::operator-=(const float& num)
{
	x -= num;
	y -= num;
	z -= num;
	return *this;
}
inline Vector3& Vector3::operator*=(const float& num)
{
	x *= num;
	y *= num;
	z *= num;
	return *this;
}

inline Vector3& Vector3::operator/=(const float& num)
{
	x /= num;
	y /= num;
	z /= num;
	return *this;
}
//Boolean
inline bool Vector3::operator==(const Vector3& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}

inline bool Vector3::operator!=(const Vector3& vector) const
{
	return x != vector.x || y != vector.y || z != vector.z;
}
#endif /* VECTOR3_H_ */
