#include <iostream>
#include <vector>

using namespace std;
vector<int> v, visited(20);
int n, s, cnt = 0;

void backtrack(int index, int m, int j)
{
	if (j == 0)
	{
		if (s == m)
			cnt++;
		return;
	}

	for (int k = index; k < n; k++)
	{
		if (!visited[k])
		{
			visited[k] = 1;
			m += v[k];
			backtrack(k, m, j - 1);
			m -= v[k];
			visited[k] = 0;
		}
	}
}

int main(void)
{
	int num;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			visited[i] = 1;
			backtrack(i, v[i], j - 1);
			visited[i] = 0;
		}
	}
	cout << cnt;
	return 0;
}