#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int t, n, m, num;
	cin >> t;
	while (t--)
	{
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> bigqueue;
		priority_queue<int> smallqueue;
		vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			cin >> m;
			smallqueue.push(m);

			if (smallqueue.size() != bigqueue.size() + 1)
			{
				bigqueue.push(smallqueue.top());
				smallqueue.pop();
			}

			if (i > 2 && bigqueue.top() < smallqueue.top())
			{
				bigqueue.push(smallqueue.top());
				smallqueue.push(bigqueue.top());
				smallqueue.pop();
				bigqueue.pop();
			}

			if (i % 2)
				ans.push_back(smallqueue.top());
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << ' ';
			if (!((i + 1) % 10))
				cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}