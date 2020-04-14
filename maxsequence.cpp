#include <iostream>
#include "maxsequence.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


/**
*	@brief Запускает логику поиска максимальной последовательности единиц.
*	@retuern Всегда возвращает 0.
*
*	Эта функция служит для чтения входа, запуска основной логики и вывода результата.
*	при отправке в тестирующую систему ее имя должно быть заменено на main.
*/
int RunMaxSequence()
{
	int size;
	cin >> size;	
	int* numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> numbers[i];		
	}	
	cout << MaxSequence(numbers, size);	
	return 0;
}

/**
*	@brief Ищет самую длинную последовательность единиц в заданном бинарном массиве.
*	@param numbers указатель на бинарный массив
*	@param size размер бинарного массива
*/
int MaxSequence(const int* numbers, const int size)
{
	if (numbers == nullptr)
	{
		return 0;
	}

	int count = 0;
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == 1)
		{
			tmp++;
			if (tmp > count)
			{
				count = tmp;
			}
		}
		else
		{			
			tmp = 0;
		}
	}
	return count;
}

/**
*	@brief Набор тестов для функции MaxSequence()
*/
void TestMaxSequence()
{
	int size = 0;
	int* numbers = new int[size];
	cout << MaxSequence(numbers, size)<<endl;
	delete numbers;


	size = 10;
	numbers = nullptr;
	cout << MaxSequence(numbers, size) << endl;

	size = 10;
	int tmp_1[10] = {1,1,1,0,1,1,0,0,0,1};
	numbers = tmp_1;
	cout << "1 Test: "<<MaxSequence(numbers, size) << endl;

	size = 5;
	int tmp_2[5] = { 0,0,1,1,1 };
	numbers = tmp_2;
	cout << "2 Test: " << MaxSequence(numbers, size) << endl;

	size = 5;
	int tmp_3[5] = { 1,1,1,0,0 };
	numbers = tmp_3;
	cout << "3 Test: " << MaxSequence(numbers, size) << endl;

	size = 5;
	int tmp_4[5] = { 0,0,0,0,0 };
	numbers = tmp_4;
	cout << "4 Test: " << MaxSequence(numbers, size) << endl;

	size = 5;
	int tmp_5[5] = { 1,1,1,1,1 };
	numbers = tmp_5;
	cout << "5 Test: " << MaxSequence(numbers, size) << endl;
}