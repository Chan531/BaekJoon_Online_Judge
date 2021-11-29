#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> sub(32001);
vector<int> check(32001), ans;
priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
	int n, m, num1, num2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		sub[num1].push_back(num2);
		check[num2]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int num = q.top();
		q.pop();

		ans.push_back(num);
		sort(sub[num].begin(), sub[num].end());

		for (int i = 0; i < sub[num].size(); i++)
		{
			check[sub[num][i]]--;
			if (!check[sub[num][i]])
				q.push(sub[num][i]);
		}
	}
	for (auto i : ans)
		cout << i << ' ';
	return 0;
}