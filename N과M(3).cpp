#include <iostream>
#include <vector>

using namespace std;

void backtrack(int n, int m, vector<int> &v, vector<int> &w)
{
	if (!m)
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = 1; j <= n; j++)
	{
		w.push_back(j);
		backtrack(n, m - 1, v, w);
		w.pop_back();
	}
}

int main(void)
{
	int n, m;
	vector<int> v, w;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = 1; i <= n; i++)
	{
		w.push_back(i);
		backtrack(n, m - 1, v, w);
		w.pop_back();
	}
	return 0;
}