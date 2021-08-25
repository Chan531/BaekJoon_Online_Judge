#include <iostream>
#include <vector>

using namespace std;

void searchcycle(vector<int> &visited, vector<int> &v, int n) 
{
	if (visited[n] != 0)
		return;

	visited[n] = 1;

	return searchcycle(visited, v, v[n]);
}

int main(void)
{
	int t, n, num, count;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v(n + 1);
		vector<int> visited(n + 1);
		count = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			v[j] = num;
		}
		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == 0)
			{
				searchcycle(visited, v, j);
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}