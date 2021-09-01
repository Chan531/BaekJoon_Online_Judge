#include <iostream>
#include <vector>

using namespace std;
vector<int> v[101];
vector<vector<int>> w(101, vector<int>(101));

void searchway(int n, int k)
{
	for (int j = 0; j < v[n].size(); j++)
	{
		if (w[k][v[n][j]] == 0)
		{
			w[k][v[n][j]] = 1;
			searchway(v[n][j], k);
		}
	}
}

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			if (num == 1)
				v[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		searchway(i, i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << w[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}