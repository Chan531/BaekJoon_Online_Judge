#include <iostream>
#include <cmath>
#define N 20
#define ll long long

using namespace std;

int n;
bool check[N];

void input()
{
	cin >> n;
}

void backtrack(int idx, ll val)
{
	if (val > n)
		return;

	if (val == n)
	{
		cout << "YES";
		exit(0);
	}

	for (int i = idx; i < N; i++)
		backtrack(i + 1, val + pow(3, i));
}

void solution()
{
	if (!n)
	{
		cout << "NO";
		return;
	}

	backtrack(0, 0);
	cout << "NO";
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

	solve();
	return 0;
}