#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, k, num;
	vector<vector<int>> nsinger(1001), fsingerlist(1001, vector<int>(1001));              // 자기보다 나중에 나와야 되는 가수, 자기보다 먼저 나와야되는 가수 명단
	vector<int> fsinger(1001), ans;                                                       // 자기보다 먼저 나와야되는 가수 수, 답
	queue<int> q;
	cin >> n >> m;
	while (m--)
	{
		cin >> k;
		vector<int> first;
		while (k--)
		{
			cin >> num;
			for (auto i : first)
			{
				if (!fsingerlist[num][i])
				{
					fsinger[num]++;
					fsingerlist[num][i]++;
					nsinger[i].push_back(num);
				}
			}
			first.push_back(num);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!fsinger[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int seq = q.front();
		q.pop();
		ans.push_back(seq);

		for (int i = 0; i < nsinger[seq].size(); i++)
		{
			int nextsinger = nsinger[seq][i];
			fsinger[nextsinger]--;
			if (fsinger[nextsinger] == 0)
				q.push(nextsinger);
		}
	}
	if (ans.size() == n)
	{
		for (auto i : ans)
			cout << i << '\n';
	}
	else
		cout << 0;
	return 0;
}