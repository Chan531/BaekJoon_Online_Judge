#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;

int calsum(int i, int j, int x, int y)
{
	int sum = 0;
	for (int a = i - 1; a <= x - 1; a++)
	{
		for (int b = j - 1; b <= y - 1; b++)
			sum += v[a][b];
	}
	return sum;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num, k, i, x, j, y;
	cin >> n >> m;
	for (int a = 0; a < n; a++)
	{
		vector<int> line;
		for (int b = 0; b < m; b++)
		{
			cin >> num;
			line.push_back(num);
		}
		v.push_back(line);
	}
	cin >> k;
	for (int a = 0; a < k; a++)
	{
		cin >> i >> j >> x >> y;
		cout << calsum(i, j, x, y) << '\n';
	}
	return 0;
}