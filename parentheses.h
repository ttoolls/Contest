﻿#pragma once

/**
*	@file
*	@brief Генерация скобочных последовательностей
*	@author Selivanov Anatoliy
	@date 05 апреля 2020
*
*	Дано целое число n. Требуется вывести все правильные скобочные последовательности длины 2 ⋅ n, упорядоченные лексикографически.
*	В задаче используются только круглые скобки.
*	Желательно получить решение, которое работает за время, пропорциональное общему количеству правильных скобочных последовательностей в ответе, 
*	и при этом использует объём памяти, пропорциональный n.
*
*	Формат ввода
*	Единственная строка входа содержит целое число n, 0 ≤ n ≤ 11
*
*	Формат вывода
*	Вывод содержит сгенерированные правильные скобочные последовательности, упорядоченные лексикографически.
*/

#include <string>

using std::string;

/**	@brief	Функция выводит все правильные скобочные последовательности длины 2 ⋅ n, упорядоченные лексикографически
*	@param n определяет половину длины скобочных последовательностей
*	@param count_close определяет сколько закрывающих скобок уже содердится в скобочной последовательности
*	@param count_open определяет сколько открывающих скобок уже содердится в скобочной последовательности
*	@param answer скобочная последовательность 
*/
void GenerateParentheses(int n, int count_close, int count_open, string answer);