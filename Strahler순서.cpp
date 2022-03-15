#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, k, m, p, a, b;
int cnt[1001], seq[1001][2];                  // 해당 노드로 들어오는 간선의 개수, 해당 노드의 순서 (순서가 i인 강이 1개인 경우, 2개 이상인 경우)
vector<int> to[1001];                         // 해당 노드에서 이어지는 노드 목록

void input()
{
	cin >> k >> m >> p;
	while (p--)
	{
		cin >> a >> b;
		cnt[b]++;
		to[a].push_back(b);
	}
}

void solution()
{
	queue<int> q;

	for (int i = 1; i <= m; i++)
	{
		if (!cnt[i])                         // 진입차수가 0인 노드라면 순서를 1로 설정 후 큐에 삽입
		{
			seq[i][0] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < to[pos].size(); i++)
		{
			int npos = to[pos][i];
			cnt[npos]--;                                    // 방문 처리

			// 다음 노드의 순서 설정

			if (seq[npos][0] < seq[pos][0])                // 순서가 현재가 더 크다면 다음 순서 갱신
				seq[npos][0] = seq[pos][0];

			else if (seq[npos][0] == seq[pos][0])          // 순서가 만약 같다면
				seq[npos][1] = max(seq[npos][1], seq[pos][0] + 1);

			if (!cnt[npos])                                // 만약 모든 진입 경로를 확인했다면 순서를 고정 후 큐에 삽입
			{
				seq[npos][0] = max(seq[npos][0], seq[npos][1]);
				q.push(npos);
			}
		}
	}
	cout << k << ' ' << max(seq[m][0], seq[m][1]) << '\n';
}

void reset()
{
	for (int i = 1; i <= m; i++)
	{
		to[i].clear();
		cnt[i] = 0;
		seq[i][0] = 0;
		seq[i][1] = 0;
	}
}

void solve()
{
	cin >> t;
	while (t--)
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