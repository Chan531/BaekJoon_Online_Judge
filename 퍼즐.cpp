#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

char c;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0},{0, -1} };
string table = "";
map<string, int> visited;

void input()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> c;
			table += c;
		}
	}
}

void solution()
{
	queue<string> q;
	q.push(table);
	visited[table] = 1;

	while (!q.empty())
	{
		string cur = q.front();
		q.pop();

		if (cur == "123456780")
			break;

		int idx = cur.find('0');
		int y = idx / 3;
		int x = idx % 3;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny > 2 || ny < 0 || nx > 2 || nx < 0)
				continue;
			
			string str = cur;

			swap(str[idx], str[ny * 3 + nx]);
			if (!visited[str])
			{
				visited[str] = visited[cur] + 1;
				q.push(str);
			}
		}
	}
	visited["123456780"] == 0 ? cout << - 1 : cout << visited["123456780"] - 1;
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