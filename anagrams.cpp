#include "anagrams.h"

#include <iostream>
#include <map>


using std::string;



/**
*	@brief ����������� �������
*	@return ����� ���������� 0
*
*	��� ������� ������ ��� ������ ����� �� ������ ����� � ������� ������, ������������� � ������� AreAnagrams().
*	��� �������� � ����������� ������� ��� ���� ������� ������� �������� �� main.
*/
int RunAnagrams()
{
	string s1, s2;
	std::cin>>s1>>s2;
	std::cout << AreAnagrams(s1, s2);
	return 0;
	
}

/**
*	@brief ��������� �������� �� ������ �����������
*	@param s1 ������ ������
*	@param s2 ������ ������
*	@return 1 ���� ������ �������� ����������� � 0 ���� ���.
*/
bool AreAnagrams(std::string s1, std::string s2)
{
	bool result = true;
	if (s1.length() != s2.length())
	{
		return false;
	}

	int charCount[26] = {0};	//�������� ������, ������ �������� ����� ��������� ��������� ���� 

	for (size_t i = 0; i < s1.length(); i++) 
	{
		charCount['z' - s1[i]] += 1;	//���� ����� ���� � ������ �����, ����������� �� �������
		charCount['z' - s2[i]] -= 1;	//���� ����� ���� �� ������ �����, ��������� �� �������
	}
	
	for (int i : charCount) //��������, ��� �������� ���� ���� ����� 0
	{
		if (i != 0)
		{
			result = false;
			break;
		}
	}
	return result;
}
