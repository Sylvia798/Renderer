#pragma once
#include "Transform.h"
#include "Color.h"

class Vertex
{
public:
	Vector3f position;
	Vector3f normal;
	Vector2 uv;
	Color color;

	Vertex();
	Vertex(const Vector3f& pos, const Vector3f& nor, const Color col, Vector2 texCor) : position(pos), normal(nor), color(col), uv(texCor) {};
	~Vertex();

private:

};
