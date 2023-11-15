#pragma once
#include <vector>
#include "Vector.h"
#include "Camera.h"
#include "Mesh.h"

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
	void DrawSingleMesh(const Mesh* mesh, const vector<Vector3i> index);
	void DrawPixel(int x, int y, COLORREF color);
	void DrawMesh(const Mesh* mesh);
	void DrawLine();
};