#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int m, vector<int>& v, vector<int>& w, vector<int>& visited)
{
	if (!m)
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = 0; j < v.size(); j++)
	{
		if (!visited[v[j]])
		{
			visited[v[j]] = 1;			
			w.push_back(v[j]);
			backtrack(m - 1, v, w, visited);
			w.pop_back();
			visited[v[j]] = 0;
		}
	}
}

int main(void)
{
	int n, m, num;
	cin >> n >> m;
	vector<int> v, w, visited(10001);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		visited[v[i]] = 1;
		w.push_back(v[i]);
		backtrack(m - 1, v, w, visited);
		w.pop_back();
		visited[v[i]] = 0;
	}
	return 0;
}