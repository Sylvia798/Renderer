#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void SplitString(string s, char splitSymbol, vector<string>& vec);
void ReadObjFile(string filePath);