#pragma once
#include <vector>
#include "Vector.h"


class Mesh
{
public:
	vector<Vector3f> positionBuffer;
	vector<Vector3f> normalBuffer;
	vector<Vector3f> colorBuffer;
	vector<Vector2> uvBuffer;
	vector<vector<Vector3i>> faceBuffer;

	
};