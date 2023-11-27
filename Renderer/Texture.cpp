#include "Texture.h"
#include <Windows.h>

void Texture::LoadTexture(LPCWSTR path)
{
	HBITMAP map = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);

	HDC hdc = CreateCompatibleDC(NULL);
	SelectObject(hdc, map);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			COLORREF color = GetPixel(hdc, i, j);
			Color c(color);
		}
	}
}