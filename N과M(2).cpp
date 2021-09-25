#include <iostream>
#include <vector>

using namespace std;
vector<int> v(9), w;
vector<int> visited(9);

void backtrack(int a, int n, int m)
{
	if (!m)
	{
		for (int k = 0; k < w.size(); k++)
		{
			cout << w[k] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int j = 1; j <= n; j++)
	{
		if (!visited[j] && a < j)
		{
			w.push_back(j);
			visited[j] = 1;
			backtrack(j, n, m - 1);
			w.pop_back();
			visited[j] = 0;
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		v[i] = i;
	for (int i = 1; i <= n; i++)
	{
		w.push_back(i);
		visited[i] = 1;
		backtrack(i, n, m - 1);
		w.pop_back();
	}
	return 0;
}