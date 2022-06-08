#include <iostream>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int n, k;
int visited[2][500001];
// 홀수 시간과 짝수 시간을 구분하여 도착시간 저장
// 홀수와 짝수 시간을 구별하는 이유 -> 동생이 언젠가 도착 가능한 지점이라면 제자리 이동이 가능하기 때문에 대기 탈 수 있음

void input()
{
	cin >> n >> k;
}

void solution()
{
	memset(visited, -1, sizeof(visited));

	queue<p> q;
	q.push({ n, 0 });

	while (!q.empty())
	{
		int pos = q.front().first;
		int t = q.front().second;
		q.pop();

		if (pos < 0 || pos > 500000 || visited[t % 2][pos] != -1)
			continue;

		visited[t % 2][pos] = t;

		q.push({ pos - 1, t + 1 });
		q.push({ pos + 1, t + 1 });
		q.push({ pos * 2, t + 1 });
	}

	int t = 0;

	for (int i = k; i <= 500000; i += t)
	{
		// 수빈이가 도착 가능하면서 동생도 그 이후에 도착이 가능하다면
		if (visited[t % 2][i] != -1 && visited[t % 2][i] <= t)
		{
			cout << t;
			return;
		}

		t++;
	}

	cout << -1;
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