#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int r, c, zr, zc;
	char letter;
	cin >> r >> c >> zr >> zc;
	vector<vector<char>> newspaper(r, vector<char>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> letter;
			newspaper[i][j] = letter;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < zr; ii++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int jj = 0; jj < zc; jj++)
					cout << newspaper[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}