#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> v, w;
map<int, int> ma;

void backtrack(int m)
{
	if (!m)
	{
		for (auto k : w)
		{
			cout << k << ' ';
		}
		cout << '\n';
		return;
	}
	for (int j = 0; j < v.size(); j++)
	{
		if (ma[v[j]])
		{
			w.push_back(v[j]);
			ma[v[j]]--;
			backtrack(m - 1);
			w.pop_back(); 
			ma[v[j]]++;
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
		if (!ma[num])
			v.push_back(num);
		ma[num]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		w.push_back(v[i]);
		ma[v[i]]--;
		backtrack(m - 1);
		w.pop_back();
		ma[v[i]]++;
	}
	return 0;
}