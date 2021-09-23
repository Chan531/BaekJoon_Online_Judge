#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (!num)
		{
			if (!q.empty())
			{
				cout << q.top().second << '\n';
				q.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			q.push(make_pair(abs(num), num));
	}
	return 0;
}