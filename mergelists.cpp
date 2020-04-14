#include "mergelists.h"
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using std::map;
using std::queue;

/**
	@brief This function merges two sorted lists
	@param l1, l2 lists to merged
	@return resulting sorted list comprising all elements of the two original lists
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	
	ListNode*result = new ListNode(0);
	ListNode* tmp = result;
	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				tmp->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else
			{
				tmp->next = new ListNode(l2->val);
				l2 = l2->next;
			}						
		}
		else
		{
			if (l1 != nullptr)
			{
				tmp->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				tmp->next = new ListNode(l2->val);
				l2 = l2->next;
			}
		}
		tmp = tmp->next;
	} 
	tmp = result;
	result = result->next; //exclude first empty node
	delete tmp;
	return result;
}

/**
	@brief This function tests mergeTwoLists()
*/
int TestMergeTwoLists()
{
	int errors = 0;
	ListNode* l1 = nullptr;
	ListNode* l2 = nullptr;

	//Test 1:
	try
	{
		mergeTwoLists(l1, l2);
	}
	catch (const std::exception& ex)
	{
		std::cout << "Test1 failed /n";
		errors++;
	}

	//Test 2
	l1 = new ListNode(0);
	ListNode* tmp = l1;
	for (int i = 1; i < 4; i++)
	{		
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	l1 = l1->next;

	l2 = new ListNode(0);
	tmp = l2;
	for (int i = 4; i < 7; i++)
	{		
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	l2 = l2->next;
	
	ListNode* res = new ListNode(0);
	tmp = res;
	for (int i = 1; i < 7; i++)
	{
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	res = res->next;
	tmp = mergeTwoLists(l1, l2);
	for (int i = 1; i < 7; i++)
	{
		if (res->val != tmp->val)
		{
			errors++;
			std::cout << "Test 2 failed! res->val: " << res->val << " != tmp->val: " << tmp->val << std::endl;
			break;
		}
		res = res->next;
		tmp = tmp->next;
	}
	return errors;
}

/**
	@brief This function reads input data and runs MergeKLists().

	When submitting to test system, the function's name should be replaced by main
*/
int RunMergeKLists()
{
	int k;
	std::cin >> k;
	map <int, int*> arrays;
	for (int i = 0; i < k; i++)
	{
		int n;
		std::cin >> n;
		int* array = new int[n];
		for (int j = 0; j < n; j++)
		{
			std::cin >> array[j];
		}
		arrays[n] = array;
	}
	return 0;
}

/**
	@brief merging k sorted lists
	@param lists is vector of k original sorted lists
	@return resulting sorted list comprising all elements of the original lists
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode*result = new ListNode(0);
	/*	
	ListNode* tmp = result;
	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				tmp->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else
			{
				tmp->next = new ListNode(l2->val);
				l2 = l2->next;
			}
		}
		else
		{
			if (l1 != nullptr)
			{
				tmp->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				tmp->next = new ListNode(l2->val);
				l2 = l2->next;
			}
		}
		tmp = tmp->next;
	}
	tmp = result;
	result = result->next;
	delete tmp;
	*/
	return result;	
}


/**
	@brief This function merges two sorted array
	@param nums1 first original array. The array should have space to add elements of the second array
	@param m number of first array's elements
	@param nums2 second original sorted array
	@param n number of second array's elements

	The function adds all elements of second array to the first array and sorts the resulting array.
*/
void MergeTwoArrays(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = 0; i < n; i++)
	{
		nums1[m + i] = nums2[i];
	}
	std::sort(nums1.begin(), nums1.end());
}

/**
	@brief Mergin two sorted vectors
	@param from first original vector should not be amended
	@param to second oroginal vector, the vector should comprise all elements of the both vectors

	The function receives two sorted vectors of int values. First vector is not amended, 
	but the second vector will comprise all elements of the two original vectors.
	The elements of the resulting vector "to" are sorted. The complexity is O(N).
*/
void MergeTwoVectors_paused(vector<int>& from, vector<int>& to)
{		
	int positionFrom = 0;
	int insertPositionTo = 0;
	queue<int> boofer;
	int sizeFrom = from.size();
	int sizeTo = to.size();

	while (insertPositionTo < sizeFrom + sizeTo)
	{
		int tmp;
		//if (Read())
		if (boofer.empty())
		{
			if (to.at(insertPositionTo) <= from.at(positionFrom))
			{
				insertPositionTo++;
			}
			else
			{
				boofer.push(to.at(insertPositionTo));
				Add(to, insertPositionTo, from.at(positionFrom));
				insertPositionTo++;
				positionFrom++;
			}
		}
		else
		{
			if (boofer.front() > from.at(positionFrom))
			{
				boofer.push(to.at(insertPositionTo));
				Add(to, insertPositionTo, from.at(positionFrom));
				insertPositionTo++;
				positionFrom++;
			}
			else
			{
				boofer.push(to.at(insertPositionTo));
				Add(to, insertPositionTo, boofer.front());
				boofer.pop();
				insertPositionTo++;
			}
		}
	}
	
}

void Add(vector<int>& dest, int position, int source)
{
	if (position >= dest.size())
	{
		dest.push_back(source);
	}
	else dest[position] = source;
}

bool Read(vector<int>& source, int position, int to)
{
	bool res=false;
	if (position < source.size())
	{
		res= true;
		to = source[position];
	}	
	return res;
}



void MergeTwoVectors(vector<int>& from, vector<int>& to)
{
	int sizeFrom = from.size();
	int sizeTo = to.size();

	int endOfTo = sizeTo;	//конец отсортированных чисел 1-го массива
	int positionFrom = 0;	//позиция во втором массиве
	int insertPositionTo = 0;	//позиция в 1-ом массиве, в которую вставляем
	int comparePositionTo = insertPositionTo;	//позиция в 1-ом массиве, с которой сравниваем

	int i = 0;

	while (positionFrom < sizeFrom || insertPositionTo < sizeTo)
	{
		i++;

		if (insertPositionTo == sizeTo) //если закончился 1-ый массив
		{
			to.push_back(from[positionFrom]);	//добавляем в него все позиции из 2-го массива
			positionFrom++;						
			continue;
		}

		if (positionFrom == sizeFrom) //если закончился 2-ой массив
		{
			if (comparePositionTo != insertPositionTo)
			{
				int tmp = to[insertPositionTo];
				to[insertPositionTo] = to[comparePositionTo];
				to[comparePositionTo] = tmp; 
				insertPositionTo++;
				continue;
			}
			else break;			
		}

		if (to[comparePositionTo] <= from[positionFrom])
		{
			if (comparePositionTo != insertPositionTo)
			{
				int tmp = to[insertPositionTo];
				to[insertPositionTo] = to[comparePositionTo];
				to[comparePositionTo] = tmp;				
			}
			insertPositionTo++;
			comparePositionTo = insertPositionTo;
		}
		else
		{
			to.push_back(to[insertPositionTo]);
			sizeTo++;
			comparePositionTo = endOfTo;
			to[insertPositionTo] = from[positionFrom];			
			insertPositionTo++;
			positionFrom++;
		}
	}
	std::cout <<"Iterations: "<< i<<std::endl;
}

void TestMergeTwoVectors()
{
	vector<int> from = { 1,2,3 };
	vector<int> to = { 4,5,6 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);	
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;
	

	from = { 2,3,5,10 };
	to = {1, 6, 7, 13};
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;

	from = { 2,5,6 };
	to = { 1,2,3 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;

	from = { 3 };
	to = { 1,2,4 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;

	from = { 1,2,4 };
	to = { 3 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;

	from = { 1,2,3 };
	to = { 4,5,6 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;

	from = { 4,5,6 };
	to = { 1,2,3 };
	std::cout << "From: ";
	PrintVector(from);
	std::cout << "To: ";
	PrintVector(to);
	MergeTwoVectors(from, to);
	std::cout << "Result: ";
	PrintVector(to);
	std::cout << std::endl;
}

void PrintVector(vector<int> v)
{
	std::cout << "{";
	for (const auto& i : v)
	{
		std::cout << i << ", ";
	}
	std::cout << '}' << std::endl;
}