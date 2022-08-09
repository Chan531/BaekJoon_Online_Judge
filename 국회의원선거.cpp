#include <iostream>
#include <queue>

using namespace std;

int n, a, b;
priority_queue<int> pq;

void input()
{
	cin >> n >> a;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> b;
		pq.push(b);
	}
}

void solution()
{
	int cnt = 0;

	while (!pq.empty() && pq.top() >= a)
	{
		int num = pq.top();
		pq.pop();
		pq.push(num - 1);
		a++;
		cnt++;
	}

	cout << cnt;
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