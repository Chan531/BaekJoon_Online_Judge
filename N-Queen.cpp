#include <iostream>

using namespace std;

int n, ans = 0, visited[16], uvisited[31], dvisited[31];          // x��ǥ �湮, ��´밢�� �湮, �϶��밢�� �湮

void nqueen(int cnt)
{
	if (cnt == n + 1)
	{
		ans++;
		return;
	}

	for (int j = 1; j <= n; j++)                                 // (cnt, j) �湮 �õ�
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
	for (int i = 1; i <= n; i++)                                // (1, i) �湮 ǥ��
	{
		visited[i] = 1;                                         // x�� i�� ��ǥ �湮 ǥ��
		uvisited[1 + i] = 1;                                    // x + y ��ǥ �湮 ǥ��
		dvisited[16 - i] = 1;                                   // y - x + 15 ��ǥ �湮 ǥ��
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