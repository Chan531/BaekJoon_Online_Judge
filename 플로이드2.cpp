#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> charge(101, vector<int>(101, 10000001));
vector<vector<vector<int>>> route(101, vector<vector<int>>(101));
int n, m, a, b, cost;

void input()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> cost;
		charge[a][b] = min(charge[a][b], cost);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			route[i][j] = { i, j };
	}
	for (int i = 1; i <= n; i++)            // i를 반드시 경유
	{
		charge[i][i] = 0;
		for (int j = 1; j <= n; j++)        // j에서 출발
		{
			for (int k = 1; k <= n; k++)    // k로 도착
			{
				if (charge[j][k] > charge[j][i] + charge[i][k])
				{
					charge[j][k] = charge[j][i] + charge[i][k];
					route[j][k].clear();
					for (int l = 0; l < route[j][i].size(); l++)
						route[j][k].push_back(route[j][i][l]);
					for (int l = 1; l < route[i][k].size(); l++)     // 0부터 넣어주면 겹침
						route[j][k].push_back(route[i][k][l]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			charge[i][j] == 10000001 ? cout << 0 << ' ' : cout << charge[i][j] << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (charge[i][j] == 10000001 || charge[i][j] == 0)
				cout << 0;
			else
			{
				cout << route[i][j].size() << ' ';
				for (int k = 0; k < route[i][j].size(); k++)
					cout << route[i][j][k] << ' ';
			}
			cout << '\n';
		}
	}
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