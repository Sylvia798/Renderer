#pragma once
#include <vector>
#include "Vector.h"
#include "Camera.h"
#include "Mesh.h"
#include "Matrix.h"
#include "Texture.h"
#include "Lighting.h"

using namespace std;
class Renderer
{
private:
	int screenWidth;
	int screenHeight;
	HDC screenHDC;

public:
	Camera* camera;
	Texture* mainTex;
	DirectionalLight* dirLight;

	Renderer(HDC hdc, int screenWidth, int screenHeight, Camera* camera, Texture* mainTexure, DirectionalLight* directionalLight);
	void DrawSingleMesh(const Mesh* mesh, const vector<Vector3i> index);
	void DrawPixel(int x, int y, COLORREF color);
	void DrawMesh(const Mesh* mesh);
	void DrawLine();
	void ViewportTransformation(float ScreenWidth, float ScreenHeight);
	void RefreshCameraTransform(CameraMovement_t type, Vector3f value = Vector3f());
	bool ZTest();
};