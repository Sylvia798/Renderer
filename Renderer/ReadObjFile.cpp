#include <iostream>

#include "ReadObjFile.h"
#include "Vector.h"
#include "Mesh.h"

using namespace std;

void SplitString(string s, char splitSymbol, vector<string>& vec, bool needIgnoreFirst)
{
	int length = s.length();
	bool newString = !needIgnoreFirst;
	int startIndex = 0;

	for (int i = 0; i < length; i++)
	{
		if (s[i] == splitSymbol && !newString)
		{
			newString = true;
			startIndex = i + 1;
		}
		else if(s[i] == splitSymbol)
		{
			vec.push_back(s.substr(startIndex, i - startIndex));
			startIndex = i + 1;
		}
		else if(i == length -1)
		{
			vec.push_back(s.substr(startIndex, i - startIndex +1));
		}
	}
}

void ReadObjFile(string FilePath, Mesh& mesh)
{
	ifstream inFile(FilePath);
	string line;
	vector<string> tmpData;
	vector<string> subTmpData;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			tmpData.clear();
			if (line[0] == 'v' && line[1] == ' ')
			{
				SplitString(line, ' ', tmpData);
				Vector3f position(stof(tmpData[0]), stof(tmpData[1]), stof(tmpData[2]));
				position.Print();
				mesh.positionBuffer.push_back(position);
			}
			else if (line[0] == 'v' && line[1] == 'n')
			{
				SplitString(line, ' ', tmpData);
				Vector3f normal(stof(tmpData[0]), stof(tmpData[1]), stof(tmpData[2]));
				normal.Print();
				mesh.normalBuffer.push_back(normal);
			}
			else if (line[0] == 'v' && line[1] == 't')
			{
				SplitString(line, ' ', tmpData);
				Vector2 uv(stof(tmpData[0]), stof(tmpData[1]));
				uv.Print();
				mesh.uvBuffer.push_back(uv);
			}
			else if (line[0] == 'f')
			{
				SplitString(line, ' ', tmpData);
				vector<Vector3i> faces;
				for (int i = 0; i < tmpData.size(); i++)
				{
					subTmpData.clear();
					SplitString(tmpData[i], '/', subTmpData, false);
					Vector3i faceVertexIndex(stoi(subTmpData[0])-1, stoi(subTmpData[1])-1, stoi(subTmpData[2])-1);
					faceVertexIndex.Print();
					faces.push_back(faceVertexIndex);
				}
				mesh.faceBuffer.push_back(faces);
			}
		}
	}
	else
	{
		cout << "no such file" << endl;
	}
}