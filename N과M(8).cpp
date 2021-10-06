#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, w, visited(10001);

void backtrack(int a, int m)
{
	if (!m)
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = a; j < v.size(); j++)
	{
		if (!visited[v[j]])
		{
			w.push_back(v[j]);
			backtrack(j, m - 1);
			w.pop_back();
		}
	}
}

int main(void)
{
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		w.push_back(v[i]);
		backtrack(i, m - 1);
		w.pop_back();
		visited[v[i]] = 1;
	}
	return 0;
}