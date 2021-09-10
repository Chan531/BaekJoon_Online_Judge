#include <iostream>
#include <vector>

using namespace std;
int t, n, k, num1, num2, st;

void divtw(vector<vector<int>>& v, vector<int>& visited, int a, int col)
{
	if (visited[a] == col)
		return;

	if (visited[a] == col * -1)
	{
		if (st == 0)
		{
			n *= -1; 
			st++;
		}
		return;
	}
	visited[a] = col;

	for (int k = 0; k < v[a].size(); k++)
		divtw(v, visited, v[a][k], col * -1);
}

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		st = 0;
		vector<int> visited(20001);
		vector<vector<int>> v(20001);
		for (int j = 0; j < k; j++)
		{
			cin >> num1 >> num2;
			v[num1].push_back(num2);
			v[num2].push_back(num1);
		}
		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == 0)
				divtw(v, visited, j, 1);
		}
		n > 0 ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}