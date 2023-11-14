#include "Render.h"

using namespace std;

vector<Vector2> testTriangle;

Renderer::Renderer(HDC hdc, int screenWidth, int screenHeight, Camera camera)
	: screenHDC(hdc), screenWidth(screenWidth), screenHeight(screenHeight), camera(camera)
{

}


void Renderer::DrawMesh()
{
	//TEST DATA
	testTriangle.push_back(Vector2(-10, 10));
	testTriangle.push_back(Vector2(0, 100));
	testTriangle.push_back(Vector2(100, 0));

	//Calculate the minimum bounding box of a triangle
	float minX = min(min(testTriangle[0].x, testTriangle[1].x), testTriangle[2].x);
	float minY = min(min(testTriangle[0].y, testTriangle[1].y), testTriangle[2].y);
	float maxX = max(max(testTriangle[0].x, testTriangle[1].x), testTriangle[2].x);
	float maxY = max(max(testTriangle[0].y, testTriangle[1].y), testTriangle[2].y);
	
	cout << testTriangle[0].x << "   " << testTriangle[1].x  << "   " << testTriangle[2].x << endl;


	//Scan the pixels inside bounding box and determin if it is inside triangle
	int XCount = (maxX - minX) / 1;
	int YCount = (maxY - minY) / 1;

	Vector2 currentPos(minX / 1, minY / 1);

	Vector2 triVec_1 = testTriangle[1] - testTriangle[0];
	Vector2 triVec_2 = testTriangle[2] - testTriangle[1];
	Vector2 triVec_3 = testTriangle[0] - testTriangle[2];

	cout << triVec_1 << endl;
	cout << triVec_2 << endl;
	cout << triVec_3 << endl;
	cout << YCount << endl;

	for (int i = 0; i < XCount; i++)
	{
		currentPos.y = minY / 1;
		for (int j = 0; j < YCount; j++)
		{
			// Use cross to see if the point is inside the triangle
			Vector2 Vec_1 = currentPos - testTriangle[0];
			Vector2 Vec_2 = currentPos - testTriangle[1];
			Vector2 Vec_3 = currentPos - testTriangle[2];

			currentPos.y += 1;
			//cout << Vector2::Cross(Vec_1, triVec_1) << endl;
			//cout << Vector2::Cross(Vec_2, triVec_2) << endl;
			//cout << Vector2::Cross(Vec_3, triVec_3) << endl;
			if (Vector2::Cross(Vec_1, triVec_1) * Vector2::Cross(Vec_2, triVec_2) > 0
				&& Vector2::Cross(Vec_1, triVec_1) * Vector2::Cross(Vec_3, triVec_3) > 0)
			{
				SetPixel(screenHDC, (int)currentPos.x, (int)currentPos.y, RGB(0, 255, 255));
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

