#include <iostream>
#include <vector>

using namespace std;

void backtrack(int a, int n, int m, vector<int>& v, vector<int>& w)
{
	if (!m)
	{
		for (auto k : w)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	for (int j = a; j <= n; j++)
	{
		w.push_back(j);
		backtrack(j, n, m - 1, v, w);
		w.pop_back();
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> v, w;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = 1; i <= n; i++)
	{
		w.push_back(i);
		backtrack(i, n, m - 1, v, w);
		w.pop_back();
	}
	return 0;
}