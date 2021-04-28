#pragma once
#include <iostream>
#include "Map.h"

class saveLoad
{
public:

	saveLoad();
	~saveLoad();
	
	static void Save(std::string fileName, int* buffer, int Y_COUNT, int X_COUNT);
	static void Load(std::string fileName, int* buffer, int size);
};
