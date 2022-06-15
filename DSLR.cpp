#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
	int pos;
	string com;
};

int a, b;
bool visited[10000];

void input()
{
	cin >> a >> b;
}

void solution()
{
	queue<node> q;
	q.push({ a, "" });
	visited[a] = 1;

	while (!q.empty())
	{
		int pos = q.front().pos;
		string com = q.front().com;
		q.pop();

		if (pos == b)
		{
			cout << com << '\n';
			break;
		}

		int D = pos * 2 % 10000;
		int S = pos - 1;		
		int L = (pos % 1000) * 10 + pos / 1000;
		int R = (pos % 10) * 1000 + pos / 10;

		if (S == -1)
			S = 9999;

		if (!visited[D])
		{
			visited[D] = 1;
			q.push({ D, com + 'D' });
		}

		if (!visited[S])
		{
			visited[S] = 1;
			q.push({ S, com + 'S' });
		}

		if (!visited[L])
		{
			visited[L] = 1;
			q.push({ L, com + 'L' });
		}

		if (!visited[R])
		{
			visited[R] = 1;
			q.push({ R, com + 'R' });
		}
	}

	memset(visited, 0, sizeof(visited));
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
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