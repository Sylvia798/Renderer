#pragma once
#include <Windows.h>
#include "Color.h"

class Texture
{
public:
	int width;
	int height;
	int channels;
	bool hasAlpha;
	Color data[1024][1024];

	Texture();
	void LoadTexture(const char* path);
	Color Sample(float u, float v);
};