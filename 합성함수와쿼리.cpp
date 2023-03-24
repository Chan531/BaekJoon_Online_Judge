#include <iostream>
#define M 200001

using namespace std;

int m, q, sparse_table[19][M];


void input()
{
	cin >> m;

	for (int i = 1; i <= m; i++)
		cin >> sparse_table[0][i];

	cin >> q;
}

void table_setting()
{
	// 2^i¹ø ÀÌµ¿ (1 << 18 == 262144)
	for (int i = 1; i <= 18; i++)
		for (int j = 1; j <= m; j++)
			sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
}

void solution()
{
	table_setting();

	while (q--)
	{
		int n, x;
		cin >> n >> x;

		for (int i = 0; i <= 18; i++)
			if (n & (1 << i))
				x = sparse_table[i][x];

		cout << x << '\n';
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