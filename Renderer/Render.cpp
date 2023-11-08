#include "Render.h"

using namespace std;

vector<Vector2> testTriangle;
void DrawMesh()
{
	//TEST DATA
	testTriangle.push_back(Vector2(-10, 10));
	testTriangle.push_back(Vector2(0, 100));
	testTriangle.push_back(Vector2(100, 0));

	//Calculate the minimum bounding box of a triangle
	float minX = min(testTriangle[0].x, testTriangle[1].x, testTriangle[2].x);
	float minY = min(testTriangle[0].y, testTriangle[1].y, testTriangle[2].y);
	float maxX = min(testTriangle[0].x, testTriangle[1].x, testTriangle[2].x);
	float maxY = min(testTriangle[0].y, testTriangle[1].y, testTriangle[2].y);


	//Calculate the centroid coordinates of a triangle
	


	//Scan the pixels inside bounding box and determin if it is inside triangle
	int XCount = (maxX - minX) / 1;
	int YCount = (maxY - minY) / 1;
	for (int i = 0; i < XCount; i++)
	{
		for (int j = 0; j < YCount; j++)
		{

		}
	}
}

void DrawLine()
{

}

