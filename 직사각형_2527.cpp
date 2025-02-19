#include <iostream>

using namespace std;

int arr[2][4];

void input()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];
}

void solution()
{
	int x = arr[0][0];
	int y = arr[0][1];
	int p = arr[0][2];
	int q = arr[0][3];

	int nx = arr[1][0];
	int ny = arr[1][1];
	int np = arr[1][2];
	int nq = arr[1][3];

	// Case d
	if (p < nx || y > nq || np < x || q < ny) cout << "d\n";

	// Case c
	else if ((p == nx && ((q == ny) || (y == nq))) || (x == np && ((y == nq) || (q == ny))))
		cout << "c\n";

	// Case b
	else if (q == ny || p == nx || y == nq || x == np)
		cout << "b\n";

	else
		cout << "a\n";
}

void solve()
{
	for (int i = 0; i < 4; i++)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}