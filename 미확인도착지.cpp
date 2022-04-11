#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int mindis[3][2001];                // 출발지 최단 경로 저장, 경유지 최단 경로 저장
// 정점의 수(n), 간선의 수(m), 후보지의 수(t), 출발지(s), 반드시 지나는 정점(g, h), 정점(a)과 정점(b) 사이의 거리(d)
int n, m, t, s, g, h, a, b, d;
int dis[2001][2001];             // 정점 사이의 거리
int target[100];                 // 후보지 목록
vector<int> connect[2001];       // 연결된 정점 저장

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

	for (int i = 1; i <= n; i++)              // 최단경로 초기화
		mindis[cur][i] = 1e9;

	mindis[cur][s] = 0;
	priority_queue<p, vector<p>, greater<p>> q;
	q.push({ 0, s });

	while (!q.empty())
	{
		int pos = q.top().second;             // 현재 위치
		int len = q.top().first;              // 지금까지의 거리
		q.pop();

		for (int i = 0; i < connect[pos].size(); i++)
		{
			int npos = connect[pos][i];
			int nlen = len + dis[pos][npos];

			if (nlen >= mindis[cur][npos])         // 최단 경로보다 길다면 pass
				continue;

			q.push({ nlen, npos });
			mindis[cur][npos] = nlen;              // npos로 가는 최단경로 갱신
		}
	}
}	

void check()
{
	sort(target, target + t);

	for (int i = 0; i < t; i++)
	{
		int test = target[i];
		// s -> g -> h -> test || s -> h -> g -> test라면 출력
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
			solution(i);            // 0 -> 시작점으로부터 최단경로, 1 -> g로부터 최단경로, 2 -> h로부터 최단경로
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