#include <iostream>

using namespace std;

int n, ans = 0, visited[16], uvisited[31], dvisited[31];          // x좌표 방문, 상승대각선 방문, 하락대각선 방문

void nqueen(int cnt)
{
	if (cnt == n + 1)
	{
		ans++;
		return;
	}

	for (int j = 1; j <= n; j++)                                 // (cnt, j) 방문 시도
	{
		if (visited[j] || uvisited[cnt + j] || dvisited[cnt - j + 15])
			continue;

		visited[j] = 1;
		uvisited[cnt + j] = 1;
		dvisited[cnt - j + 15] = 1;
		nqueen(cnt + 1);
		visited[j] = 0;
		uvisited[cnt + j] = 0;
		dvisited[cnt - j + 15] = 0;
	}
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)                                // (1, i) 방문 표시
	{
		visited[i] = 1;                                         // x가 i인 좌표 방문 표시
		uvisited[1 + i] = 1;                                    // x + y 좌표 방문 표시
		dvisited[16 - i] = 1;                                   // y - x + 15 좌표 방문 표시
		nqueen(2);
		visited[i] = 0;
		uvisited[1 + i] = 0;
		dvisited[16 - i] = 0;
	}
	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}