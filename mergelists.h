#pragma once

/**
*	@file
*	@brief Слияние k сортированных списков
*	@author Selivanov Anatoliy
	@date 05 апреля 2020
*
*	Даны k отсортированных в порядке неубывания массивов неотрицательных целых чисел, каждое из которых не превосходит 100.
*	Требуется построить результат их слияния: отсортированный в порядке неубывания массив, содержащий все элементы исходных k массивов.
*	Длина каждого массива не превосходит 10 ⋅ k.
*	Постарайтесь, чтобы решение работало за время k ⋅ log(k) ⋅ n, если считать, что входные массивы имеют длину n.
*
*	Формат ввода
*	Первая строка входного файла содержит единственное число k, k ≤ 1024.
*	Каждая из следующих k строк описывает по одному массиву. 
*	Первое число каждой строки равняется длине соответствующего массива, 
*	оставшиеся числа этой строки описывают значения элементов этого же массива. 
*	Элементы массивов являются неотрицательными целыми числами и не превосходят 100.
*
*	Формат вывода
*	Выход содержит отсортированный в порядке неубывания массив, содержащий все элементы исходных массивов.
*/

#include <vector>
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

/**
	@brief This function merges two sorted lists
	@param l1, l2 lists to merged
	@return resulting sorted list comprising all elements of the two original lists
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

/**
	@brief This function tests mergeTwoLists()
*/
int TestMergeTwoLists();


/**
	@brief This function reads input data and runs MergeKLists().

	When submitting to test system, the function's name should be replaced by main
*/
int RunMergeKLists();

/**
	@brief merging k sorted lists
	@param lists is vector of k original sorted lists
	@return resulting sorted list comprising all elements of the original lists
*/
ListNode* mergeKLists(vector<ListNode*>& lists);

/**
	@brief This function merges two sorted array
	@param nums1 first original array. The array should have space to add elements of the second array
	@param m number of first array's elements
	@param nums2 second original sorted array
	@param n number of second array's elements

	The function adds all elements of second array to the first array and sorts the resulting array.
*/
void MergeTwoArrays(vector<int>& nums1, int m, vector<int>& nums2, int n);

/**
	@brief Mergin two sorted vectors
	@param from first original vector should not be amended
	@param to second oroginal vector, the vector should comprise all elements of the both vectors

	The function receives two sorted vectors of int values. First vector is not amended,
	but the second vector will comprise all elements of the two original vectors.
	The elements of the resulting vector "to" are sorted. The complexity is O(N).
*/
void MergeTwoVectors(vector<int>& from, vector<int>& to);

void TestMergeTwoVectors();

void Add(vector<int>& dest, int to, int source);

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

void PrintVector(vector<int> v);