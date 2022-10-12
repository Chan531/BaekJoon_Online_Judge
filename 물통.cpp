#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int a, b, c;
};

int a, b, c;
vector<int> arr;
bool visited[201][201][201];

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	queue<node> q;
	q.push({ 0, 0, c });

	while (!q.empty())
	{
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();

		if (visited[x][y][z])
			continue;

		visited[x][y][z] = 1;

		if (x == 0)
			arr.push_back(z);

		// x에서 다른 곳으로 물을 붓는 경우
		if (x != 0)
		{
			// y가 가득 찬 상태가 아닐 경우
			if (y != b)
			{
				// x를 다 부어도 될 때
				if (b - y >= x)
					q.push({ 0, x + y, z });

				// x를 다 붓기 전에 y가 가득 찰 때
				else
					q.push({ x - b + y, b, z });
			}

			// z가 가득 찬 상태가 아닐 경우
			if (z != c)
			{
				// x를 다 부어도 될 때
				if (c - z >= x)
					q.push({ 0, y, z + x });

				// x를 다 붓기 전에 z가 가득 찰 때
				else
					q.push({ x - c + z, y, c });
			}
		}

		// y에서 다른 곳으로 물을 붓는 경우
		if (y != 0)
		{
			// x가 가득 찬 상태가 아닐 경우
			if (x != a)
			{
				// y를 다 부어도 될 때
				if (a - x >= y)
					q.push({ x + y, 0, z });

				// y를 다 붓기 전에 x가 가득 찰 때
				else
					q.push({ a, y - a + x, z });
			}

			// z가 가득 찬 상태가 아닐 경우
			if (z != c)
			{
				// y를 다 부어도 될 때
				if (c - z >= y)
					q.push({ x, 0, z + y });

				// y를 다 붓기 전에 z가 가득 찰 때
				else
					q.push({ x, y - c + z, c });
			}
		}

		// z에서 다른 곳으로 물을 붓는 경우
		if (z != 0)
		{
			// x가 가득 찬 상태가 아닐 경우
			if (x != a)
			{
				// z를 다 부어도 될 때
				if (a - x >= z)
					q.push({ x + z, y, 0 });

				// z를 다 붓기 전에 x가 가득 찰 때
				else
					q.push({ a, y, z - a + x });
			}

			// y가 가득 찬 상태가 아닐 경우
			if (y != b)
			{
				// z를 다 부어도 될 때
				if (b - y >= z)
					q.push({ x, y + z, 0 });

				// z를 다 붓기 전에 y가 가득 찰 때
				else
					q.push({ x, b, z - b + y });
			}
		}
	}

	sort(arr.begin(), arr.end());

	for (auto i : arr)
		cout << i << ' ';
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