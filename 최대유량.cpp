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

// 문자를 숫자로
int alphatonum(char c)
{
	// 대문자 : 26 ~ 51
	if (isupper(c))
		return c - 'A' + 26;

	// 소문자 : 0 ~ 25
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

		// 다음 노드 설정
		path[startnum].push_back(endnum);
		path[endnum].push_back(startnum);

		// 양방향 간선이므로 둘 다 더해줌 (병렬)
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

		// source -> sink로 갈 수 있는 모든 경로 탐색
		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == sink)
				break;

			for (int i = 0; i < path[pos].size(); i++)
			{
				int npos = path[pos][i];

				// 아직 더 흘려보낼 수 있고 방문한 적이 없다면
				if (capacity[pos][npos] - flow[pos][npos] > 0 && visited[npos] == -1)
				{
					visited[npos] = pos;
					q.push(npos);
				}
			}
		}

		// 모든 경로를 탐색했을 시
		if (visited[sink] == -1)
			break;

		int sum = 1e9;

		// queue를 통해 알아낸 경로에서 최소 유량 탐색
		for (int i = sink; i != source; i = visited[i])
			sum = min(sum, capacity[visited[i]][i] - flow[visited[i]][i]);

		// 최소 유량 적용 (음의 유량 계산)
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