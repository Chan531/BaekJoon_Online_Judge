#include <iostream>
#include <queue>

using namespace std;

int n, m, child[100000], ans = 1;
priority_queue<int> present;

void input()
{
	cin >> n >> m;

	while (n--)
	{
		int num;
		cin >> num;
		present.push(num);
	}

	for (int i = 0; i < m; i++)
		cin >> child[i];
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		int p = present.top();
		present.pop();

		if (child[i] > p)
		{
			ans = 0;
			break;
		}

		if (p > child[i])
			present.push(p - child[i]);
	}

	cout << ans;
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