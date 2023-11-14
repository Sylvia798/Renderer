#pragma once
#include <vector>
#include "Vector.h"
#include "Camera.h"

using namespace std;
class Renderer
{
private:
	int screenWidth;
	int screenHeight;
	HDC screenHDC;

public:
	Camera camera;

	Renderer(HDC hdc, int screenWidth, int screenHeight, Camera camera);
	void DrawMesh();
	void DrawLine();
};