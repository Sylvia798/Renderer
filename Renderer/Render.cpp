#include "Render.h"

using namespace std;

vector<Vector2> currentTriangle;
Matrix MVPMatrix;
Matrix ViewportMatrix; //transform[-1, 1] cube to [0, screenWidth] [0, screenHeight]


Renderer::Renderer(HDC hdc, int screenWidth, int screenHeight, Camera camera)
	: screenHDC(hdc), screenWidth(screenWidth), screenHeight(screenHeight), camera(camera)
{
	ViewportTransformation(screenWidth, screenHeight);
	camera.SetCameraTransform(Vector3f(0, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, -1));
	camera.Orthographic(0, 120, Vector2(-10, 10), Vector2(-10, 10));


	Matrix ModelMat;
	cout << ModelMat << endl;

	ModelMat = ModelMat.Scale(Vector3f(0.1, 0.1, 0.1));
	//ModelMat = ModelMat.Translate(Vector3f(screenWidth /2, screenHeight /2, 0));
	cout << camera.ProjectionMatrix << endl;

	MVPMatrix = camera.ProjectionMatrix * camera.ViewMatrix * ModelMat;
	//MVPMatrix = camera.ViewMatrix * ModelMat;
	//MVPMatrix = ModelMat;
	cout << MVPMatrix << endl;

	MVPMatrix = ModelMat;
}

void Renderer::DrawMesh(const Mesh* mesh)
{
	int faceCount = mesh->faceBuffer.size();
	vector<Vector2> triangleVertexs;
	cout << "Face Count:" << faceCount;
	for (int i = 0; i < faceCount; i++)
	{
		triangleVertexs.clear();
		for (int j = 0; j < 3; j++)
		{
			DrawSingleMesh(mesh, mesh->faceBuffer[i]);
		}
	}
}

void Renderer::DrawSingleMesh(const Mesh* mesh, const vector<Vector3i> faceVertexIndex)
{
	//TEST DATA
	currentTriangle.push_back(Vector2(-10, 10));
	currentTriangle.push_back(Vector2(0, 100));
	currentTriangle.push_back(Vector2(100, 0)); 
	
	Vector2 vec1(mesh->positionBuffer[faceVertexIndex[0].x].x, mesh->positionBuffer[faceVertexIndex[0].x].y);
	Vector2 vec2(mesh->positionBuffer[faceVertexIndex[1].x].x, mesh->positionBuffer[faceVertexIndex[1].x].y);
	Vector2 vec3(mesh->positionBuffer[faceVertexIndex[2].x].x, mesh->positionBuffer[faceVertexIndex[2].x].y);

	//cout << faceVertexIndex[0].x << endl;
	//cout << mesh->positionBuffer[faceVertexIndex[0].x] << endl;
	//cout << mesh->positionBuffer[faceVertexIndex[0].x].x << endl;

	currentTriangle.clear();
	vec1 = MVPMatrix * vec1;
	vec2 = MVPMatrix * vec2;
	vec3 = MVPMatrix * vec3;
	currentTriangle.push_back(vec1);
	currentTriangle.push_back(vec2);
	currentTriangle.push_back(vec3);

	//cout << vec1 << endl;
	//cout << vec2 << endl;
	//cout << vec3 << endl;

	//Calculate the minimum bounding box of a triangle
	float minX = min(min(currentTriangle[0].x, currentTriangle[1].x), currentTriangle[2].x);
	float minY = min(min(currentTriangle[0].y, currentTriangle[1].y), currentTriangle[2].y);
	float maxX = max(max(currentTriangle[0].x, currentTriangle[1].x), currentTriangle[2].x);
	float maxY = max(max(currentTriangle[0].y, currentTriangle[1].y), currentTriangle[2].y);
	
	//cout << currentTriangle[0].x << "   " << currentTriangle[1].x  << "   " << currentTriangle[2].x << endl;


	//Scan the pixels inside bounding box and determin if it is inside triangle
	int XCount = (maxX - minX) / 1;
	int YCount = (maxY - minY) / 1;

	Vector2 currentPos(minX / 1, minY / 1);

	Vector2 triVec_1 = currentTriangle[1] - currentTriangle[0];
	Vector2 triVec_2 = currentTriangle[2] - currentTriangle[1];
	Vector2 triVec_3 = currentTriangle[0] - currentTriangle[2];

	//viewport transformation
	triVec_1 = ViewportMatrix * triVec_1;
	triVec_2 = ViewportMatrix * triVec_2;
	triVec_3 = ViewportMatrix * triVec_3;

	cout << triVec_1 << endl;
	cout << triVec_2 << endl;
	cout << triVec_3 << endl;
	//cout << YCount << endl;

	for (int i = 0; i < XCount; i++)
	{
		currentPos.y = minY / 1;
		for (int j = 0; j < YCount; j++)
		{
			// Use cross to see if the point is inside the triangle
			Vector2 Vec_1 = currentPos - currentTriangle[0];
			Vector2 Vec_2 = currentPos - currentTriangle[1];
			Vector2 Vec_3 = currentPos - currentTriangle[2];

			currentPos.y += 1;

			if (Vector2::Cross(Vec_1, triVec_1) * Vector2::Cross(Vec_2, triVec_2) > 0
				&& Vector2::Cross(Vec_1, triVec_1) * Vector2::Cross(Vec_3, triVec_3) > 0)
			{
				cout << "run here" << endl;
				DrawPixel((int)currentPos.x, (int)currentPos.y, RGB(0, 255, 255));
			}
		}
		currentPos.x += 1;
	}

	//currentXPos = 0;
	//currentYPos = 0;
	//for (int i = 0; i < 800; i++)
	//{
	//	currentYPos = 0;
	//	for (int j = 0; j < 800; j++)
	//	{
	//		// Use cross to see if the point is inside the triangle
	//		currentYPos += 1;
	//		SetPixel(screenHDC, currentXPos, currentYPos, RGB(0, 255, 255));
	//	}
	//	currentXPos += 1;
	//}
}

void Renderer::DrawLine()
{

}

void Renderer::ViewportTransformation(float screenWidth, float screenHeight)
{
	ViewportMatrix.value[0][0] = screenWidth / 2;
	ViewportMatrix.value[1][1] = screenHeight / 2;
	ViewportMatrix.value[0][3] = screenWidth / 2;
	ViewportMatrix.value[1][3] = screenHeight / 2;
}

void Renderer::DrawPixel(int x, int y, COLORREF color)
{
	SetPixel(screenHDC, x, y, color);
}


