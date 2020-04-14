#include "Sum.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

static int errors = 0;

int Sum(int a, int b)
{
	return a+b;
}

int RunSum()
{
	int A, B;
	cin >> A >> B;
	cout << Sum(A, B);
	return 0;
}

/*
int RunSum()
{
	std::ifstream iFile;
	iFile.open("input.txt");
	int A, B;
	iFile >> A >> B;
	iFile.close();

	std::ofstream oFile;
	oFile.open("output.txt");
	oFile << Sum(A, B);
	oFile.close();
	return 0;
}
*/
void TestSum()
{
	int A, B, C;
	
	
	cerr << "1 Test: ";
	A = 2;
	B = 2;
	C = 4;
	Assert(A, B, C);

	cerr << "2 Test: ";
	A = 57;
	B = 43;
	C = 100;
	Assert(A, B, C);

	cerr << "3 Test: ";
	A = 123456789;
	B = 673243342;
	C = 796700131;
	Assert(A, B, C);

	cerr << "4 Test: ";
	A = (-2) * 10 ^ (9);
	B = (-2) * 10 ^ (9);;
	C = 100;
	Assert(A, B, C);
}

void Assert(int A, int B, int C)
{
	if (Sum(A, B) != C)
	{
		cerr << "error" << endl <<
			"A+B = " << Sum(A, B) <<
			"expected " << C << endl;
		errors++;
	}
	else
	{
		cerr << "OK" << endl;
	}
}