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
				cout << q.top() * -1 << '\n';
				q.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			q.push(-1 * num);
	}
	return 0;
}