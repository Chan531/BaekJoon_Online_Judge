#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 400

using namespace std;

int n, p, ans;
vector<int> path[801];
int capacity[801][801], flow[801][801], visited[801];

void setstat()
{
	// ���� ���� -> ���� ���� ����ġ(�뷮)�� ũ�Ⱑ 1�� ����(in -> out) ����
	for (int i = 1; i <= n; i++)
	{
		path[i].push_back(i + N);
		path[i + N].push_back(i);

		capacity[i][i + N] = 1;
	}
}

void input()
{
	cin >> n >> p;

	setstat();

	while (p--)
	{
		int a, b;

		cin >> a >> b;

		// ���� a�� out�� ���� b�� in ����
		// ���� b�� in�� ���� a�� out ���� -> ������ ����
		// ���� b�� out�� ���� a�� in ����
		// ���� a�� in�� ���� b�� out ���� -> ������ ����
		path[a + N].push_back(b);
		path[b].push_back(a + N);
		path[b + N].push_back(a);
		path[a].push_back(b + N);

		// ������ ������ �뷮�� 0�̹Ƿ� ���� x
		capacity[a + N][b] = 1;
		capacity[b + N][a] = 1;
	}
}

void solution()
{
	while (1)
	{
		queue<int> q;
		q.push(1);
		memset(visited, -1, sizeof(visited));
		visited[1] = 0;

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == 2)
				break;

			for (int i = 0; i < path[pos].size(); i++)
			{
				int npos = path[pos][i];

				if (capacity[pos][npos] - flow[pos][npos] > 0 && visited[npos] == -1)
				{
					q.push(npos);
					visited[npos] = pos;
				}
			}
		}

		if (visited[2] == -1)
			break;

		// ���� 1�� 2 ������ ������ �ǵ帮�� �ʵ��� ���� ����
		// 401 -> ���� 1�� out.
		for (int i = 2; i != 401; i = visited[i])
		{
			flow[visited[i]][i]++;
			flow[i][visited[i]]--;
		}

		ans++;
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