#include "Vec2.hpp"
#include <math.h>

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

void Vec2::add(const Vec2& v) {
	x += v.x;
	y += v.y;
}

void Vec2::sub(const Vec2& v) {
	x -= v.x;
	y -= v.y;
}

void Vec2::scale(const float n) {
	x *= n;
	y *= n;
}

Vec2 Vec2::rotate(const float angle) const {
	Vec2 result;
	result.x = x * cos(angle) - y * sin(angle);
	result.y = x * sin(angle) + y * cos(angle);
	return result;
}

float Vec2::magnitude() const {
	return sqrtf(x * x + y * y);
}

float Vec2::magnitudeSquared() const {
	return (x * x + y * y);
}

Vec2& Vec2::normalize() {
	float length = magnitude();
	if (length != 0.0) {
		x /= length;
		y /= length;
	}
    return *this;
}

Vec2 Vec2::unitVector() const {
	Vec2 result = Vec2(0, 0);
	float length = magnitude();
	if (length != 0.0) {
		result.x = x / length;
		result.y = y / length;
	}
    return result;
}

Vec2 Vec2::normal() const {
	return Vec2(y, -x).normalize();
}

float Vec2::dot(const Vec2& v) const {
    return (x * v.x) + (y * v.y);
}

float Vec2::cross(const Vec2& v) const {
	return (x * v.y) - (y * v.x);
}