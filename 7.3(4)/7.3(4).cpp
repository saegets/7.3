#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void Printkilk(int* kilk, const int rowNo, const int rowCount)
{
	cout << setw(4) << kilk[rowNo];
	if (rowNo < rowCount - 1)
		Printkilk(kilk, rowNo+1,rowCount);
	else
		cout << endl;
}

void sameInRow(int** a, int rowNo, const int colCount, int colNo, int* kilk)
{
	if (a[rowNo][colNo] == a[rowNo][colNo + 1])
			kilk[rowNo]++;
	if (colNo < colCount - 1)
		sameInRow(a, rowNo, colCount, colNo + 1, kilk);
	
}

void sameInRows(int** a, const int rowCount, const int colCount, int rowNo, int colNo, int* kilk)
{
	kilk[rowNo] = 0;
	sameInRow(a, rowNo, colCount, 0, kilk);
		if (rowNo < rowCount - 1)
			sameInRows(a, rowCount, colCount, rowNo + 1, 0, kilk);
}

void searchmax(int* kilk, const int rowCount, int rowNo, int max, int& nomer)
{
	if (kilk[rowNo] > max)
	{
		max = kilk[rowNo];
		nomer = rowNo + 1;
	}
	if (rowNo < rowCount - 1)
		searchmax(kilk, rowCount, rowNo + 1, max, nomer);
}

int main()
{
	srand((unsigned)time(NULL));

	int Low = -2;
	int High = 5;

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	int* kilk = new int[rowCount];
	CreateRows(a, rowCount, colCount, Low, High, 0);
	//InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);
	sameInRows(a, rowCount, colCount, 0, 0, kilk);
	cout << "kilkist odnakovuh elemenyiv poriadkovo: "; Printkilk(kilk, 0, rowCount);
	int nomer = 0;

	searchmax(kilk, rowCount, 0, 0, nomer);
	cout << "nomer riadka = "  << nomer << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
