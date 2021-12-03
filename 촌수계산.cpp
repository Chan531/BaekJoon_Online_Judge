#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> relationship(101);
vector<int> visited(101);
int ans = -1;

void findrelation(int a, int b, int cnt)
{
	for (int i = 0; i < relationship[a].size(); i++)
	{
		if (relationship[a][i] == b)
		{
			ans = cnt + 1;
			return;
		}
		if (!visited[relationship[a][i]])
		{
			visited[relationship[a][i]] = 1;
			findrelation(relationship[a][i], b, cnt + 1);
		}
	}
}

int main(void)
{
	int n, a, b, m, x, y;
	cin >> n >> a >> b >> m;
	while (m--)
	{
		cin >> x >> y;
		relationship[x].push_back(y);
		relationship[y].push_back(x);
	}
	visited[a] = 1;
	findrelation(a, b, 0);
	cout << ans;
	return 0;
}