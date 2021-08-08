#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num;
	vector<int> v, w;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		w.push_back(num);
	}
	copy(w.begin(), w.end(), back_inserter(v));
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i << ' ';
	return 0;
}