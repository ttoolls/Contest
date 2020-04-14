#include <iostream>

#include "Gems.h"
#include "maxsequence.h"
#include "duplicates.h"
#include "parentheses.h"
#include "anagrams.h"
#include "mergelists.h"
#include "palletes.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


void RunGemsCount();


int main()
{	
	
	
	//merge(from, from.size(), to, to.size());
	TestMergeTwoVectors();
	return 0;
}


void RunGemsCount()
{
	string gems;
	string stones;
	cin >> gems;
	cin >> stones;
	cout << GemsCount(gems, stones) << endl;
}