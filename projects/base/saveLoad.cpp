#include "saveLoad.h"
#include <string>
#include <iostream>
#include <app.h>

saveLoad::saveLoad()
{
}

saveLoad::~saveLoad()
{
}

void saveLoad::Save(std::string fileName, int* buffer, int Y_COUNT, int X_COUNT)
{
	std::ofstream file;
	file.open(fileName);
	for (size_t y = 0; y < Y_COUNT; y++)
	{
		for (size_t x = 0; x < X_COUNT; x++)
		{
			int i = x + y * X_COUNT;
			file << buffer[i] << ", ";
		}
		file << std::endl;
	}
	file.close();
}

void saveLoad::Load(std::string fileName, int* buffer, int size)
{
	{
		std::string line;
		std::ifstream mysave(fileName);

		int i = 0;

		if (mysave.is_open())
		{
			int commaIndex = -1;

			while (std::getline(mysave, line))
			{
				while (true)
				{
					int cutStart = commaIndex + 1;
					commaIndex = line.find(',', commaIndex + 1);

					std::string numStr = line.substr(cutStart, commaIndex - cutStart);

					if (commaIndex < 0)
						break;

					int num = std::stoi(numStr);
					buffer[i] = num;
					i++;
					std::cout << num << " ";
				}
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << "Can't load file" << std::endl;
		}
	}
}