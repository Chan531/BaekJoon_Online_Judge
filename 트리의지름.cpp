#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define p pair<int, int>
#define N 10001

using namespace std;

struct node {
	int start, pos, dis;
};

int n, answer;
vector<int> arr;
vector<p> path[N];
bool check[N], visited[N];

void input()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		path[a].push_back({ b, c });
		path[b].push_back({ a, c });
		check[a] = 1;
	}
}

// 자식이 없는 노드 골라주기
void setarr()
{
	for (int i = 1; i <= n; i++)
		if (!check[i])
			arr.push_back(i);
}

// 중복 체크 방지를 위해 지금까지 찾아온 자식 노드 방문 체크
void setvisited(int k)
{
	for (int i = 0; i <= k; i++)
		visited[arr[i]] = 1;
}

void solution()
{
	setarr();

	for (int i = 0; i < arr.size(); i++)
	{
		memset(visited, 0, sizeof(visited));
		queue<node> q;
		q.push({ arr[i], arr[i], 0 });
		setvisited(i);

		while (!q.empty())
		{
			int start = q.front().start;
			int pos = q.front().pos;
			int dis = q.front().dis;
			q.pop();

			answer = max(answer, dis);

			for (int j = 0; j < path[pos].size(); j++)
			{
				int npos = path[pos][j].first;

				if (visited[npos])
					continue;

				visited[npos] = 1;
				q.push({ start, npos, dis + path[pos][j].second });
			}
		}
	}

	cout << answer;
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