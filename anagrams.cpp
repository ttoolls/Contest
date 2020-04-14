#include "anagrams.h"

#include <iostream>
#include <map>


using std::string;



/**
*	@brief Запускающая функция
*	@return сегда возвращает 0
*
*	Эта функция служит для чтения строк из потока ввода и запуска логики, реализованной в функции AreAnagrams().
*	При отправке в тестирующую систему имя этой функции следует заменить на main.
*/
int RunAnagrams()
{
	string s1, s2;
	std::cin>>s1>>s2;
	std::cout << AreAnagrams(s1, s2);
	return 0;
	
}

/**
*	@brief Проверяет являются ли строки анаграммами
*	@param s1 первая строка
*	@param s2 вторая строка
*	@return 1 если строки являются анаграммами и 0 если нет.
*/
bool AreAnagrams(std::string s1, std::string s2)
{
	bool result = true;
	if (s1.length() != s2.length())
	{
		return false;
	}

	int charCount[26] = {0};	//Создадим массив, размер которого равен количству возможных букв 

	for (size_t i = 0; i < s1.length(); i++) 
	{
		charCount['z' - s1[i]] += 1;	//если буква есть в первом слове, увеличиваем ее счетчик
		charCount['z' - s2[i]] -= 1;	//если буква есть во втором слове, уменьшаем ее счетчик
	}
	
	for (int i : charCount) //проверим, что счетчики всех букв равны 0
	{
		if (i != 0)
		{
			result = false;
			break;
		}
	}
	return result;
}
