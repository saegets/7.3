#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void sameInRow(int** a, const int rowCount, const int colCount, int* kilk);
void searchmax(int* kilk, const int rowCount, int& nomer);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 1;
	int High = 15;

	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	int *kilk = new int[rowCount];
	
	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	sameInRow(a, rowCount, colCount, kilk);
	cout << "kilkist odnakovuh elementiv poriadkovo = {";
	for (int i = 0; i < rowCount; i++)
	cout << setw(4) << kilk[i] << ", ";
	cout << "}";
	cout << endl;
	
	int nomer = 0;
	searchmax(kilk, rowCount, nomer);
	
	cout << "maximum odnakovuh v riadku: " << nomer << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void sameInRow(int** a, const int rowCount, const int colCount, int* kilk)
{
		for (int i = 0; i < rowCount; i++)
		{
			kilk[i] = 0;
			for (int j = 0; j < colCount; j++)
			{
				if (a[i][j] == a[i][j + 1])
				{
					kilk[i]++;
				}
			}
		}
	}

void searchmax(int* kilk, const int rowCount, int& nomer)
{
	int	max = 0;
	for (int i = 0; i < rowCount; i++)
	{
		if (kilk[i] > max)
		{
			max = kilk[i];
			nomer = i + 1;
		}
		else if (kilk[i] = max)
			nomer = nomer;
	}
}
