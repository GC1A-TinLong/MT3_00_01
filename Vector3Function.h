#pragma once
#include <Novice.h>
#include <math.h>

struct Vector3 {
	float x, y, z;
};
static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

Vector3 operator+(const Vector3 &v1, const Vector3& v2);
Vector3 operator-(const Vector3 &v1, const Vector3& v2);
Vector3 operator*(float scalar, const Vector3& v);

float Dot(Vector3& v1, Vector3& v2);
float Length(const Vector3& v);
Vector3 Normailize(const Vector3& v);