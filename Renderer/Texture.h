#pragma once
#include "Color.h"

class Texture
{
public:
	int width;
	int height;
	Color data[1024][1024];

	void LoadTexture(const char* path);
};