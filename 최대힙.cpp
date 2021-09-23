#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (!num)
		{
			if (!q.empty())
			{
				cout << q.top() << '\n';
				q.pop();
			}
			else
				cout << 0 << '\n';
			continue;
		}
		q.push(num);
	}
	return 0;
}