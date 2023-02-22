#include <iostream>

using namespace std;

int n;
string s;
bool ans[5][6051], a[5][3], b[5][3], c[5][3], d[5][3], e[5][3];

void input()
{
	cin >> n >> s;
}

void A(int i)
{
	ans[0][i] = 1;
	ans[0][i + 1] = 1;
	ans[0][i + 2] = 1;
	ans[1][i] = 1;
	ans[1][i + 2] = 1;
	ans[2][i] = 1;
	ans[2][i + 1] = 1;
	ans[2][i + 2] = 1;
	ans[3][i] = 1;
	ans[3][i + 2] = 1;
	ans[4][i] = 1;
	ans[4][i + 2] = 1;
}

void B(int i)
{
	ans[0][i] = 1;
	ans[0][i + 1] = 1;
	ans[0][i + 2] = 1;
	ans[1][i] = 1;
	ans[1][i + 2] = 1;
	ans[2][i] = 1;
	ans[2][i + 1] = 1;
	ans[2][i + 2] = 1;
	ans[3][i] = 1;
	ans[3][i + 2] = 1;
	ans[4][i] = 1;
	ans[4][i + 1] = 1;
	ans[4][i + 2] = 1;
}

void C(int i)
{
	ans[0][i] = 1;
	ans[0][i + 1] = 1;
	ans[0][i + 2] = 1;
	ans[1][i] = 1;
	ans[2][i] = 1;
	ans[3][i] = 1;
	ans[4][i] = 1;
	ans[4][i + 1] = 1;
	ans[4][i + 2] = 1;
}

void D(int i)
{
	ans[0][i] = 1;
	ans[0][i + 1] = 1;
	ans[0][i + 2] = 1;
	ans[1][i] = 1;
	ans[1][i + 2] = 1;
	ans[2][i] = 1;
	ans[2][i + 2] = 1;
	ans[3][i] = 1;
	ans[3][i + 2] = 1;
	ans[4][i] = 1;
	ans[4][i + 1] = 1;
	ans[4][i + 2] = 1;
}

void E(int i)
{
	ans[0][i] = 1;
	ans[0][i + 1] = 1;
	ans[0][i + 2] = 1;
	ans[1][i] = 1;
	ans[2][i] = 1;
	ans[2][i + 1] = 1;
	ans[2][i + 2] = 1;
	ans[3][i] = 1;
	ans[4][i] = 1;
	ans[4][i + 1] = 1;
	ans[4][i + 2] = 1;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A')
			A(i * 3);

		else if (s[i] == 'B')
			B(i * 3);

		else if (s[i] == 'C')
			C(i * 3);

		else if (s[i] == 'D')
			D(i * 3);

		else
			E(i * 3);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n * 3; j++)
		{
			if (ans[i][j])
				cout << '*';

			else
				cout << '.';
		}

		cout << '\n';
	}
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}