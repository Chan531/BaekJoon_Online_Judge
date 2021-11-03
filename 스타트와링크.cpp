#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<int>> v(21, vector<int>(21));
vector<int> visited(21);
int n, dif = 3600;

int checkscore(int m)
{
	int startscore = 0;
	int linkscore = 0;
	for (int s = 1; s <= 2 * m; s++)
	{
		for (int t = s + 1; t <= 2 * m; t++)
		{
			if (visited[s] && visited[t])
				startscore += v[s][t] + v[t][s];
		}
	}
	for (int s = 1; s <= 2 * m; s++)
	{
		for (int t = s + 1; t <= 2 * m; t++)
		{
			if (!visited[s] && !visited[t])
				linkscore += v[s][t] + v[t][s];
		}
	}
	return abs(startscore - linkscore);
}

void maketeam(int a, int m)
{
	if (m == n / 2)
	{
		int score = checkscore(m);
		if (dif > score)
			dif = score;
		return;
	}
	for (int j = a + 1; j <= n; j++)
	{
		if (!visited[j])
		{
			visited[j] = 1;
			maketeam(j, m + 1);
			visited[j] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			v[i][j] = num;
		}
	}
	visited[1] = 1;
	maketeam(1, 1);
	cout << dif;
	return 0;
}