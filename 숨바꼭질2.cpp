#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, cp, ct ,mt = 100000, num;
	queue<pair<int, int>> q;
	vector<int> visited(100001, 100000);
	cin >> n >> k;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		cp = q.front().first;
		ct = q.front().second;	
		q.pop();

		if (cp < 0 || cp > 100000 || ct > mt)
			continue;

		if (visited[cp] >= ct)
			visited[cp] = ct;

		else
			continue;

		if (cp == k)
		{
			if (mt > ct)
			{
				mt = ct;
				num = 1;
			}
			else if (mt == ct)
				num++;
		}

		else
		{
			q.push(make_pair(cp - 1, ct + 1));
			if (cp < k)
			{
				q.push(make_pair(cp + 1, ct + 1));
				q.push(make_pair(cp * 2, ct + 1));
			}
		}
	}
	cout << mt << '\n' << num;
	return 0;
}