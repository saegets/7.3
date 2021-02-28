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

int colZero(int** a, const int rowCount, int colCount, int colNo, int rowNo, int& kilkist)
{
	if (a[rowNo][colNo] == 0)
	{
		kilkist++;
		colZero(a, rowCount, colCount, colNo + 1, 0, kilkist);
	}
	else if (rowNo < rowCount - 1)
		colZero(a, rowCount, colCount, colNo, rowNo + 1, kilkist);

	else if (colNo < colCount - 1)
		colZero(a, rowCount, colCount, colNo + 1, 0, kilkist);

	return kilkist;
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

	CreateRows(a, rowCount, colCount, Low, High, 0);
	//InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);
	int kilkist = 0;
	cout << "kilkist stovpciv = " << colZero(a, rowCount, colCount, 0, 0, kilkist) << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
