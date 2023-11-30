#include "Render.h"

using namespace std;

vector<Vector3f> currentTriangle;
float AspectRatio;
Matrix ModelMat;
Matrix MVPMatrix;
Matrix ViewportMatrix; //transform[-1, 1] cube to [0, screenWidth] [0, screenHeight]



Renderer::Renderer(HDC hdc, int screenWidth, int screenHeight, Camera* camera, Texture* mainTexture, DirectionalLight* directionalLight)
	: screenHDC(hdc), screenWidth(screenWidth), screenHeight(screenHeight), camera(camera), mainTex(mainTexture), dirLight(directionalLight)
{
	//for (int i = 0; i < 500; i++)
	//{
	//	for (int j = 0; j < 500; j++)
	//	{
	//		DrawPixel(i, j, RGB(mainTex->data[i][j].r * 255, mainTex->data[i][j].g * 255, mainTex->data[i][j].b * 255));
	//	}
	//}
	depthBuffer = new float* [screenHeight];
	for (int i = 0; i < screenHeight; i++)
	{
		depthBuffer[i] = new float[screenWidth];
		for (int j = 0; j < screenWidth; j++)
		{
			depthBuffer[i][j] = 2;
		}
	}

	ViewportTransformation(screenWidth, screenHeight);
	//use aspect ratio and screenHeight to calculate the related width of the camera
	AspectRatio = (float)screenHeight / (float)screenWidth;

	//instatiate camera parameters
	camera->SetCameraTransform(Vector3f(0, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, -1));
	camera->Orthographic(0, 120, Vector2(-10, 10), Vector2(-10 * AspectRatio, 10 * AspectRatio));

	RefreshCameraTransform(CameraMovement_t::None);
}



void Renderer::RefreshCameraTransform(CameraMovement_t type, Vector3f value)
{
	switch (type)
	{
	case CameraMovement_t::Move:
		break;
	case CameraMovement_t::Rotate:
		break;
	case CameraMovement_t::Scale:
		camera->Scale(value.x);
		break;
	default:
		break;
	}
	cout << "ModelMat:" << ModelMat << endl;

	//ModelMat = ModelMat.Scale(Vector3f(0.1, 0.1, 0.1));
	//ModelMat = ModelMat.Scale(Vector3f(100, 100, 100));
	//ModelMat = ModelMat.Translate(Vector3f(screenWidth /2, screenHeight /2, 0));
	cout << "ProjectionMatrix:" << camera->ProjectionMatrix << endl;

	//MVPMatrix = camera.ViewMatrix * ModelMat;
	cout << "ViewMatrix:" << camera->ViewMatrix << endl;

	//MVPMatrix = ModelMat;
}

void Renderer::DrawMesh(const Mesh* mesh)
{
	MVPMatrix = camera->ProjectionMatrix * camera->ViewMatrix * ModelMat;
	cout << "mvp mat:" << MVPMatrix << endl;

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
	//currentTriangle.push_back(Vector2(-10, 10));
	//currentTriangle.push_back(Vector2(0, 100));
	//currentTriangle.push_back(Vector2(100, 0)); 
	
	Vector3f vec1(mesh->positionBuffer[faceVertexIndex[0].x]);
	Vector3f vec2(mesh->positionBuffer[faceVertexIndex[1].x]);
	Vector3f vec3(mesh->positionBuffer[faceVertexIndex[2].x]);

	Vector2 uv1(mesh->uvBuffer[faceVertexIndex[0].y]);
	Vector2 uv2(mesh->uvBuffer[faceVertexIndex[1].y]);
	Vector2 uv3(mesh->uvBuffer[faceVertexIndex[2].y]);

	//cout << "uv1:" << uv1 << endl;
	//cout << "uv2:" << uv2 << endl;
	//cout << "uv3:" << uv3 << endl;

	//cout << faceVertexIndex[0].x << endl;
	//cout << mesh->positionBuffer[faceVertexIndex[0].x] << endl;
	//cout << mesh->positionBuffer[faceVertexIndex[0].x].x << endl;

	currentTriangle.clear();

	//mvp transformation and viewport transformation
	//cout << "v ma:" << ViewportMatrix << MVPMatrix << ViewportMatrix * MVPMatrix << endl;
	//cout << "vec1:" << vec1 << endl;
	//cout << "vec2:" << vec2 << endl;
	//cout << "vec3:" << vec3 << endl;
	vec1 = ViewportMatrix * MVPMatrix * vec1;
	vec2 = ViewportMatrix * MVPMatrix * vec2;
	vec3 = ViewportMatrix * MVPMatrix * vec3;
	//cout << "vec1:" << vec1 << endl;
	//cout << "vec2:" << vec2 << endl;
	//cout << "vec3:" << vec3 << endl;		
	currentTriangle.push_back(vec1);
	currentTriangle.push_back(vec2);
	currentTriangle.push_back(vec3);

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
	//cout << "currentPos" << currentPos << endl;

	Vector3f triVec_1 = currentTriangle[1] - currentTriangle[0];
	Vector3f triVec_2 = currentTriangle[2] - currentTriangle[1];
	Vector3f triVec_3 = currentTriangle[0] - currentTriangle[2];
	//cout << YCount << endl;

	Vector3f triVec_4 = currentTriangle[2] - currentTriangle[0];
	float triangleArea = Vector2::Cross(Vector2(triVec_1.x, triVec_1.y), Vector2(triVec_4.x, triVec_4.y));
	for (int i = 0; i < XCount; i++)
	{
		currentPos.y = minY / 1;
		for (int j = 0; j < YCount; j++)
		{
			// Use cross to see if the point is inside the triangle
			Vector2 Vec_1 = currentPos - Vector2(currentTriangle[0].x, currentTriangle[0].y);
			Vector2 Vec_2 = currentPos - Vector2(currentTriangle[1].x, currentTriangle[1].y);
			Vector2 Vec_3 = currentPos - Vector2(currentTriangle[2].x, currentTriangle[2].y);

			currentPos.y += 1;
			float triArea1 = Vector2::Cross(Vec_1, Vector2(triVec_1.x, triVec_1.y));
			float triArea2 = Vector2::Cross(Vec_2, Vector2(triVec_2.x, triVec_2.y));
			float triArea3 = Vector2::Cross(Vec_3, Vector2(triVec_3.x, triVec_3.y));

			if(triArea1* triArea2 > 0 && triArea1 * triArea3 > 0)
			{
				//Calculate Barycentric Coordinates
				float gamma1 = triArea2 / triangleArea;
				float gamma2 = triArea3 / triangleArea;
				float gamma3 = triArea1 / triangleArea;

				float ZLerp = currentTriangle[0].z * gamma1 + currentTriangle[1].z * gamma2 + currentTriangle[2].z * gamma3;
				if (ZTest(currentPos.x, currentPos.y, ZLerp, false))
				{
					Vector2 uv = uv1 * gamma1 + uv2 * gamma2 + uv3 * gamma3;
					Color pixelCol = mainTex->Sample(uv.x, uv.y);
					DrawPixel((int)currentPos.x, (int)currentPos.y, RGB(pixelCol.r * 255, pixelCol.g * 255, pixelCol.b * 255));
				}
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

bool Renderer::ZTest(int x, int y, float depth, bool transparent)
{
	if (depth <= depthBuffer[y][x])
	{
		depthBuffer[y][x] = depth;
		return true;
	}
	return false;
}

