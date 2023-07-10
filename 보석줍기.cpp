#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define p pair<int, int>
#define N 101
#define K 15

using namespace std;

int n, m, k, jew[N], visited[N][1 << K];
vector<p> con[N];

void input()
{
	cin >> n >> m >> k;

	int cnt = 1;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		jew[num] = cnt++;
	}

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		con[a].push_back({ b, c });
		con[b].push_back({ a, c });
	}
}

// limit�� +1�� ���ְ� ret�� -1�� ���ִ� ���� : jew[cur] == 0�� ��쿡�� ��Ʈ�� count��.
int bfs()
{
	int ret = 0;
	queue<p> q;
	q.push({ 1, 1 });
	visited[1][1] = 1;

	while (!q.empty())
	{
		int cur = q.front().first;
		int bit = q.front().second;
		int cnt = bitset<K>(bit).count();
		int nbit = bit | (1 << jew[cur]);
		q.pop();

		if (cur == 1)
		{
			if (jew[cur] && (bit ^ nbit))
				ret = max(ret, cnt + 1);

			else
				ret = max(ret, cnt);
		}

		for (int i = 0; i < con[cur].size(); i++)
		{
			int next = con[cur][i].first;
			int limit = con[cur][i].second + 1;

			// �̹� ��ҿ��� ������ �ݴ� ���
			if (jew[cur] && (bit ^ nbit) && !visited[next][nbit] && cnt < limit)
			{
				visited[next][nbit] = 1;
				q.push({ next, nbit });
			}

			// �̹� ��ҿ��� ������ ���� �ʴ� ���
			if (!visited[next][bit] && cnt <= limit)
			{
				visited[next][bit] = 1;
				q.push({ next, bit });
			}
		}
	}

	return ret - 1;
}

void solution()
{
	cout << bfs();
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