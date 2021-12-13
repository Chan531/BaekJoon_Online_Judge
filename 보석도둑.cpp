#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, m, v, idx = 0;
	long long ans = 0;
	vector<int> weight;
	vector<pair<int, int>> jewel;
	priority_queue<int> pq;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewel.push_back(make_pair(m, v));
	}
	for (int i = 0; i < k; i++)
	{
		cin >> m;
		weight.push_back(m);
	}
	sort(jewel.begin(), jewel.end());
	sort(weight.begin(), weight.end());
	for (int i = 0; i < k; i++)
	{
		while (idx < n && weight[i] >= jewel[idx].first)
			pq.push(jewel[idx++].second);

		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}