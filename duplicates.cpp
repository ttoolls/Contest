#include "duplicates.h"

#include <iostream>
#include <fstream>

/**
*	@brief Функция удаляет дубликаты
*
*	Чтение производится из файла input.txt, вывод происходит в output.txt
*/
int Duplicates(void)
{
	std::ifstream iFile;
	iFile.open("input.txt");
	
	int number = 0;
	iFile >> number;
	
	std::ofstream oFile;
	oFile.open("output.txt");
	
	int current;
	iFile >> current;
	if (!iFile.eof())
	{
		oFile << current << std::endl;
	}
	int prev = current;
	for (int i = 1; i < number; i++)
	{
		iFile >> current;
		if (current != prev)
		{
			oFile << current<<std::endl;
			prev = current;
		}
	}
	iFile.close();
	oFile.close();
	return 0;
}

