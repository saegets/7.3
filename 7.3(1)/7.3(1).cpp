#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int colZero(int** a, const int rowCount, const int colCount, int& kilkist);

int main()
{
	srand((unsigned)time(NULL));
	
	int Low = -2;
	int High = 5;
	
	int rowCount, colCount, kilkist;
	
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	
	Print(a, rowCount, colCount);
	
	if (colZero(a, rowCount, colCount, kilkist))
		cout << "kilkist stovpciv = " << colZero(a, rowCount, colCount, kilkist) << endl;
	else
		cout << "there is no zero elements" << endl;
	
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

int colZero(int** a, const int rowCount, const int colCount, int& kilkist)
{
	kilkist = 0;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			if (a[i][j] == 0)
			{
				kilkist++;
				break;
			}
		}
	}
	return kilkist;
}