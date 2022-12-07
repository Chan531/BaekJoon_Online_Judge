#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, w, l,arr[1000];
int t, idx, cnt;

void input()
{
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	queue<p> q;

	while (cnt != n)
	{
		if (!q.empty() && q.front().first + w == t)
		{
			l += q.front().second;
			q.pop();
			cnt++;
		}

		// 다리에 트럭이 더 진입할 수 있는 상태
		if (l >= arr[idx] && q.size() < w)
		{
			l -= arr[idx];
			q.push({ t, arr[idx++] });
		}

		t++;
	}

	cout << t;
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