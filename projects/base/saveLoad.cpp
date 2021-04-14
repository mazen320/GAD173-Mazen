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

void loop()
{
	{
		std::string line = "10, 50, 60, 800, 900, 087";

		int start = 0;
		int index = -1;

		while (true)
		{
			start = index + 1;
			index = line.find(",");

			std::string numStr = line.substr(start, index - start);

			std::cout << numStr << std::endl;
		}
	}
}