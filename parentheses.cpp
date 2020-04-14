#include "parentheses.h"

#include <iostream>
#include <vector>
using std::vector;

/**	@brief	Функция выводит все правильные скобочные последовательности длины 2 ⋅ n, упорядоченные лексикографически
*	@param n определяет половину длины скобочных последовательностей
*	@param count_close определяет сколько закрывающих скобок уже содердится в скобочной последовательности
*	@param count_open определяет сколько открывающих скобок уже содердится в скобочной последовательности
*	@param answer скобочная последовательность
*/
void GenerateParentheses(int n, int count_open, int count_close, string answer)
{
	if (count_close + count_open == 2 * n)
	{
		std::cout << answer<<std::endl;		
	}
	if (count_open < n)
	{
		GenerateParentheses(n, count_open + 1, count_close, answer + '(');
	}
	if (count_open > count_close)
	{
		GenerateParentheses(n, count_open, count_close + 1, answer + ')');
	}
}

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		generateCombination(n, 0, 0, "", result);
		return result;
	}
	void generateCombination(int n, int opened, int closed, string cur, vector<string> res)
	{
		if (opened + closed == 2 * n)
		{
			res.push_back(cur);
		}
		if (opened < n)
		{
			generateCombination(n, opened + 1, closed, cur + '(', res);
		}
		if (closed < opened)
		{
			generateCombination(n, opened, closed + 1, cur + ')', res);
		}
	}

};