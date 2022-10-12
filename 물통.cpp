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

		// x���� �ٸ� ������ ���� �״� ���
		if (x != 0)
		{
			// y�� ���� �� ���°� �ƴ� ���
			if (y != b)
			{
				// x�� �� �ξ �� ��
				if (b - y >= x)
					q.push({ 0, x + y, z });

				// x�� �� �ױ� ���� y�� ���� �� ��
				else
					q.push({ x - b + y, b, z });
			}

			// z�� ���� �� ���°� �ƴ� ���
			if (z != c)
			{
				// x�� �� �ξ �� ��
				if (c - z >= x)
					q.push({ 0, y, z + x });

				// x�� �� �ױ� ���� z�� ���� �� ��
				else
					q.push({ x - c + z, y, c });
			}
		}

		// y���� �ٸ� ������ ���� �״� ���
		if (y != 0)
		{
			// x�� ���� �� ���°� �ƴ� ���
			if (x != a)
			{
				// y�� �� �ξ �� ��
				if (a - x >= y)
					q.push({ x + y, 0, z });

				// y�� �� �ױ� ���� x�� ���� �� ��
				else
					q.push({ a, y - a + x, z });
			}

			// z�� ���� �� ���°� �ƴ� ���
			if (z != c)
			{
				// y�� �� �ξ �� ��
				if (c - z >= y)
					q.push({ x, 0, z + y });

				// y�� �� �ױ� ���� z�� ���� �� ��
				else
					q.push({ x, y - c + z, c });
			}
		}

		// z���� �ٸ� ������ ���� �״� ���
		if (z != 0)
		{
			// x�� ���� �� ���°� �ƴ� ���
			if (x != a)
			{
				// z�� �� �ξ �� ��
				if (a - x >= z)
					q.push({ x + z, y, 0 });

				// z�� �� �ױ� ���� x�� ���� �� ��
				else
					q.push({ a, y, z - a + x });
			}

			// y�� ���� �� ���°� �ƴ� ���
			if (y != b)
			{
				// z�� �� �ξ �� ��
				if (b - y >= z)
					q.push({ x, y + z, 0 });

				// z�� �� �ױ� ���� y�� ���� �� ��
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