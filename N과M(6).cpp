#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int m, int index, vector<int>& v, vector<int>& w, vector<int>& visited)
{
	if (!m)
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = index; j < v.size(); j++)
	{
		if (!visited[v[j]])
		{
			w.push_back(v[j]);
			visited[v[j]] = 1;
			backtrack(m - 1, j, v, w, visited);
			w.pop_back();
			visited[v[j]] = 0;
		}
	}
}

int main(void)
{
	int n, m, num;
	vector<int> v, w, visited(10001);
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
		visited[v[i]] = 1;
		backtrack(m - 1, i, v, w, visited);
		w.pop_back();
	}
	return 0;
}