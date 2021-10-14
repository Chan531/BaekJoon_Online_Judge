#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, e, ma = 0, t, cnt = 1;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ e, s });
	}
	sort(v.begin(), v.end());
	t = v[0].first;
	for (int i = 1; i < n; i++)
	{
		if (v[i].second >= t)
		{
			t = v[i].first;
			cnt++;
		}
	}
	cout << cnt;
}