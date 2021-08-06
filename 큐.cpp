#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> q;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			q.push_back(num);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q[0] << '\n';
				q.erase(q.begin());
			}
			else
				cout << -1 << '\n';
		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty")
		{
			!q.empty() ? cout << 0 << '\n' : cout << 1 << '\n';
			
		}
		else if (s == "front")
		{
			if (!q.empty())
				cout << q[0] << '\n';
			else
				cout << -1 << '\n';
		}
		else
		{
			if (!q.empty())
				cout << q[q.size() - 1] << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}