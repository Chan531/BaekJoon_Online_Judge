#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int n, d, c, a, b, s;
int t[10001];             // n��° ��ǻ�Ͱ� �����Ǳ���� �ɸ��� �ð�
vector<p> rel[10001];     // n��° ��ǻ�Ϳ� ����� ��ǻ���� ��ȣ�� ������

void input()
{
	cin >> n >> d >> c;

	while (d--)
	{
		cin >> a >> b >> s;
		rel[b].push_back({ a, s });
	}
}

void solution()
{
	int com = 0, totaltime = 0;

	for (int i = 1; i <= n; i++)           // t�迭 �ʱ�ȭ
		t[i] = 1e9;

	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, c });
	t[c] = 0;

	while (!pq.empty())
	{
		int dis = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (t[pos] < dis)
			continue;

		totaltime = max(totaltime, dis);

		for (int i = 0; i < rel[pos].size(); i++)
		{
			int npos = rel[pos][i].first;
			int ndis = rel[pos][i].second + dis;

			if (ndis < t[npos])
			{
				t[npos] = ndis;
				pq.push({ ndis, npos });
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (t[i] != 1e9)
			com++;

	cout << com << ' ' << totaltime << '\n';
}

void reset()
{
	memset(t, 0, sizeof(t));

	for (int i = 1; i <= n; i++)
		rel[i].clear();
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
		reset();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}