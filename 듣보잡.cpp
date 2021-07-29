#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	map<string, int> k;
	vector<string> v, w;
	string s = "";
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < n; i++)
		k[v[i]]++;
	for (int i = n; i < n + m; i++)
		k[v[i]]--;
	for (int i = 0; i < n; i++)
		if (k[v[i]] == 0)
			w.push_back(v[i]);
	cout << w.size() << '\n';
	sort(w.begin(), w.end());
	for (auto i : w)
		cout << i << '\n';
	return 0;
}