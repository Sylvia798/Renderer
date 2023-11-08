#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Mesh.h"

using namespace std;

void SplitString(string s, char splitSymbol, vector<string>& vec, bool needIgnoreFirst = true);
void ReadObjFile(string filePath, Mesh& mesh);