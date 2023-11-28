#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cmath>
#include <fstream>

#include "Texture.h"

using namespace std;

Texture::Texture()
{
	width = 1024;
	height = 1024;
	channels = 4;
	hasAlpha = false;
}

void Texture::LoadTexture(const char* path)
{
	unsigned char* img = stbi_load(path, &width, &height, &channels, 4);
	if (img)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int index = 4 * (i * width + j);
				Color c(img[index]/255.0, img[index + 1]/255.0, img[index + 2]/255.0, img[index + 3]/255.0);
				data[i][j] = c;
			}
		}
		stbi_image_free(img);
	}
	else
	{

	}
	cout << "herere" << endl;
}

Color Texture::Sample(float u, float v)
{
	u = fmod(u, 1.0f);
	if (u < 0) u += 1;
	v = fmod(v, 1.0f);
	if (v < 0) v += 1;
	int su = u * width;
	int sv = v * height;
	return data[su][sv];
}