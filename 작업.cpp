#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, time, pre, work, nextwork, ans = 0;
	cin >> n;
	vector<int> pretask(n + 1), tasktime(n + 1);
	vector<vector<int>> nexttask(n + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> working;
	for (int i = 1; i <= n; i++)
	{
		cin >> time >> pre;
		tasktime[i] = time;
		while (pre--)
		{
			cin >> work;
			pretask[i]++;
			nexttask[work].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!pretask[i])
			working.push(make_pair(tasktime[i], i));
	}
	while (!working.empty())
	{
		time = working.top().first;
		work = working.top().second;
		working.pop();

		ans = max(ans, time);

		for (int i = 0; i < nexttask[work].size(); i++)
		{
			nextwork = nexttask[work][i];
			pretask[nextwork]--;
			if (!pretask[nextwork])
				working.push(make_pair(time + tasktime[nextwork], nextwork));
		}
	}
	cout << ans;
	return 0;
}