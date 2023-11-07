#include "ReadObjFile.h"
#include "Vector.h"

using namespace std;

//TODO NEED TEST
void SplitString(string s, char splitSymbol, vector<string>& vec)
{
	int length = s.length();
	bool newString = false;
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
			vec.push_back(s.substr(startIndex, i - 1));
		}
		else if(i == length -1)
		{
			vec.push_back(s.substr(startIndex, i));
		}
	}
}

void ReadObjFile(string FilePath)
{
	ifstream inFile(FilePath);
	string line;
	vector<string> tmpData;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			tmpData.clear();
			if (line[0] == 'v' && line[1] == ' ')
			{
				SplitString(line, ' ', tmpData);
				Vector3f position(stof(tmpData[0]), stof(tmpData[1]), stof(tmpData[2]));
			}
			else if (line[0] == 'v' && line[1] == 'n')
			{
				SplitString(line, ' ', tmpData);
				Vector3f normal(stof(tmpData[0]), stof(tmpData[1]), stof(tmpData[2]));
			}
			else if (line[0] == 'v' && line[1] == 't')
			{
				SplitString(line, ' ', tmpData);
				Vector2 uv(stof(tmpData[0]), stof(tmpData[1]));
			}
			else if (line[0] == 'f')
			{
				SplitString(line, ' ', tmpData);
			}
		}
	}
	else
	{
		cout << "no such file" << endl;
	}
}