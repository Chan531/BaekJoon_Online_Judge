#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 52
#define source 26
#define sink 51
// 26 -> 'A', 51 -> 'Z'

using namespace std;

int n, capacity[N][N], flow[N][N], visited[N], ans;
vector<int> path[N];

// ���ڸ� ���ڷ�
int alphatonum(char c)
{
	// �빮�� : 26 ~ 51
	if (isupper(c))
		return c - 'A' + 26;

	// �ҹ��� : 0 ~ 25
	else
		return c - 'a';
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char start, end;
		int cost;

		cin >> start >> end >> cost;

		int startnum = alphatonum(start);
		int endnum = alphatonum(end);

		// ���� ��� ����
		path[startnum].push_back(endnum);
		path[endnum].push_back(startnum);

		// ����� �����̹Ƿ� �� �� ������ (����)
		capacity[startnum][endnum] += cost;
		capacity[endnum][startnum] += cost;
	}
}

int MaxFlow()
{
	while (1)
	{
		memset(visited, -1, sizeof(visited));
		queue<int> q;
		q.push(source);

		// source -> sink�� �� �� �ִ� ��� ��� Ž��
		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == sink)
				break;

			for (int i = 0; i < path[pos].size(); i++)
			{
				int npos = path[pos][i];

				// ���� �� ������� �� �ְ� �湮�� ���� ���ٸ�
				if (capacity[pos][npos] - flow[pos][npos] > 0 && visited[npos] == -1)
				{
					visited[npos] = pos;
					q.push(npos);
				}
			}
		}

		// ��� ��θ� Ž������ ��
		if (visited[sink] == -1)
			break;

		int sum = 1e9;

		// queue�� ���� �˾Ƴ� ��ο��� �ּ� ���� Ž��
		for (int i = sink; i != source; i = visited[i])
			sum = min(sum, capacity[visited[i]][i] - flow[visited[i]][i]);

		// �ּ� ���� ���� (���� ���� ���)
		for (int i = sink; i != source; i = visited[i])
		{
			flow[visited[i]][i] += sum;
			flow[i][visited[i]] -= sum;
		}

		ans += sum;
	}

	return ans;
}

void solution()
{
	cout << MaxFlow();
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