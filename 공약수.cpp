#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

void input()
{
	cin >> n;

	while (n--)
	{
		int m;
		cin >> m;

		q.push(m);
	}
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	while (q.size() != 1)
	{
		int a = q.front();
		q.pop();

		int b = q.front();
		q.pop();

		q.push(gcd(a, b));
	}

	int m = q.front();

	for (int i = 1; i <= m; i++)
	{
		if (m % i)
			continue;

		cout << i << '\n';
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