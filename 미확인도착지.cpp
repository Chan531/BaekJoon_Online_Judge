#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int mindis[3][2001];                // ����� �ִ� ��� ����, ������ �ִ� ��� ����
// ������ ��(n), ������ ��(m), �ĺ����� ��(t), �����(s), �ݵ�� ������ ����(g, h), ����(a)�� ����(b) ������ �Ÿ�(d)
int n, m, t, s, g, h, a, b, d;
int dis[2001][2001];             // ���� ������ �Ÿ�
int target[100];                 // �ĺ��� ���
vector<int> connect[2001];       // ����� ���� ����

void input()
{
	cin >> n >> m >> t >> s >> g >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> d;
		dis[a][b] = d;
		dis[b][a] = d;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	for (int i = 0; i < t; i++)
		cin >> target[i];
}

void solution(int cur)
{
	if (cur == 1)
		s = g;
	
	if (cur == 2)
		s = h;

	for (int i = 1; i <= n; i++)              // �ִܰ�� �ʱ�ȭ
		mindis[cur][i] = 1e9;

	mindis[cur][s] = 0;
	priority_queue<p, vector<p>, greater<p>> q;
	q.push({ 0, s });

	while (!q.empty())
	{
		int pos = q.top().second;             // ���� ��ġ
		int len = q.top().first;              // ���ݱ����� �Ÿ�
		q.pop();

		for (int i = 0; i < connect[pos].size(); i++)
		{
			int npos = connect[pos][i];
			int nlen = len + dis[pos][npos];

			if (nlen >= mindis[cur][npos])         // �ִ� ��κ��� ��ٸ� pass
				continue;

			q.push({ nlen, npos });
			mindis[cur][npos] = nlen;              // npos�� ���� �ִܰ�� ����
		}
	}
}	

void check()
{
	sort(target, target + t);

	for (int i = 0; i < t; i++)
	{
		int test = target[i];
		// s -> g -> h -> test || s -> h -> g -> test��� ���
		if (mindis[0][test] == mindis[0][g] + mindis[1][h] + mindis[2][test] || mindis[0][test] == mindis[0][h] + mindis[2][g] + mindis[1][test])
			cout << test << ' ';
	}

	cout << '\n';
}

void reset()
{
	memset(dis, 0, sizeof(dis));

	for (int i = 1; i <= n; i++)
		connect[i].clear();
}

void solve()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		input();
		for (int i = 0; i < 3; i++)
			solution(i);            // 0 -> ���������κ��� �ִܰ��, 1 -> g�κ��� �ִܰ��, 2 -> h�κ��� �ִܰ��
		check();
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