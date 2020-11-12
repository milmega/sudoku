#include <iostream>
#include<vector>
#include<utility>
using namespace std;

vector <int> boxes[10];

int whichBox(int x, int y)
{
	if (x < 3)
	{
		if (y < 3) return 1;
		if (y < 6) return 2;
		else return 3;
	}
	if (x < 6)
	{
		if (y < 3) return 4;
		if (y < 6) return 5;
		else return 6;
	}
	else
	{
		if (y < 3) return 7;
		if (y < 6) return 8;
		else return 9;
	}
}

bool isSafe(int arr[9][9], int x, int y, int a)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[x][i] == a) return false;
		if (arr[i][y] == a) return false;
	}

	int b = whichBox(x, y);

	for (int i = 0; i < boxes[b].size(); i++)
		if (a == boxes[b][i]) return false;

	return true;
}

void show(int arr[9][9])
{
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		if (k % 3 == 0)
		{
			for (int j = 0; j < 25; j++) cout << "-";
			cout << endl;
		}

		for (int j = 0; j < 10; j++)
		{
			if (j % 3 == 0) cout << "| ";
			if (j < 9) cout << arr[i][j] << " ";
		}
		k++;
		cout << endl;
	}
	for (int j = 0; j < 25; j++) cout << "-";
	cout << endl << endl;
}


void add2Box(int numberOfBox, int a)
{
	boxes[numberOfBox].push_back(a);
}

void deleteFromBox(int numberOfBox)
{
	boxes[numberOfBox].pop_back();
}

void updateVector(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] != 0)
			{
				int k = whichBox(i, j);
				boxes[k].push_back(arr[i][j]);
			}
		}
	}
}

bool findEmpty(int arr[9][9], int &x, int &y)
{
	for(x = 0; x < 9; x++)
		for(y = 0; y < 9; y++)
			if (arr[x][y] == 0) return true;
	return false;
}

bool solve(int arr[9][9])
{
	int x, y; //cordinates
	
	if (findEmpty(arr, x, y) == false) return true;
	
	int b = whichBox(x, y);
	
	for (int i = 1; i < 10; i++)
	{
		if (isSafe(arr, x, y, i))
		{
			arr[x][y] = i;
			add2Box(b, i);
			if(solve(arr)) return true;
			deleteFromBox(b);
			arr[x][y] = 0;
		}
	}
	return false;
}

int main()
{
	//board3 - expert
	int board3[9][9] =
	{
		  { 0 , 4 , 0 , 0 , 0 , 0 , 1 , 0 , 0 },
		  { 6 , 0 , 8 , 0 , 0 , 0 , 0 , 4 , 0 },
		  { 0 , 0 , 0 , 0 , 2 , 7 , 0 , 6 , 0 },
		  { 0 , 9 , 7 , 0 , 0 , 0 , 0 , 0 , 0 },
		  { 0 , 0 , 0 , 5 , 0 , 0 , 0 , 3 , 0 },
		  { 0 , 0 , 0 , 7 , 6 , 0 , 0 , 0 , 0 },
		  { 0 , 0 , 2 , 0 , 0 , 9 , 0 , 5 , 0 },
		  { 0 , 5 , 0 , 0 , 0 , 0 , 9 , 2 , 0 },
		  { 8 , 0 , 0 , 0 , 0 , 6 , 0 , 0 , 3 }
	};

	//board2 - hard
	int board2[9][9] =
	{
		  { 9 , 7 , 0 , 6 , 0 , 0 , 0 , 0 , 0 },
		  { 2 , 0 , 1 , 0 , 3 , 0 , 0 , 0 , 0 },
		  { 0 , 0 , 0 , 0 , 0 , 0 , 6 , 4 , 0 },
		  { 0 , 0 , 0 , 5 , 0 , 0 , 0 , 0 , 4 },
		  { 0 , 8 , 6 , 3 , 0 , 2 , 0 , 0 , 9 },
		  { 0 , 0 , 0 , 1 , 0 , 0 , 0 , 3 , 0 },
		  { 5 , 0 , 0 , 0 , 0 , 0 , 7 , 0 , 0 },
		  { 0 , 2 , 0 , 0 , 5 , 0 , 0 , 9 , 0 },
		  { 0 , 0 , 0 , 4 , 0 , 0 , 0 , 6 , 2 }
	};

	//board1 - medium
	int board1[9][9] =
	{
		  { 0 , 0 , 9 , 0 , 8 , 0 , 0 , 0 , 0 },
		  { 1 , 6 , 0 , 7 , 3 , 0 , 5 , 0 , 0 },
		  { 0 , 3 , 8 , 0 , 1 , 9 , 7 , 6 , 0 },
		  { 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 , 0 },
		  { 0 , 2 , 0 , 0 , 0 , 1 , 3 , 4 , 0 },
		  { 0 , 0 , 0 , 4 , 7 , 0 , 0 , 5 , 0 },
		  { 9 , 1 , 0 , 5 , 0 , 0 , 0 , 2 , 7 },
		  { 6 , 0 , 0 , 0 , 0 , 2 , 0 , 0 , 0 },
		  { 0 , 5 , 0 , 0 , 0 , 0 , 6 , 0 , 0 }
	};

	show(board3);
	updateVector(board3);

	if (solve(board3) == true) show(board3);

	return 0;
}
