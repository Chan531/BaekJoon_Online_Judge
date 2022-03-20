#include <iostream>
#define ull unsigned long long

using namespace std;

int n, m;
ull arr[70];

void input()
{
	cin >> n;
}

void setdp()
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
}

ull solution()
{
	cin >> m;
	for (int i = 4; i <= m; i++)
	{
		if (arr[i])
			continue;
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
	}
	return arr[m];
}

void solve()
{
	input();
	setdp();
	while (n--)
		cout << solution() << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}