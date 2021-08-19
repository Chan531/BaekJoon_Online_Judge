#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	deque<int> v;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> num;
			v.push_front(num);
		}
		else if (s == "push_back")
		{
			cin >> num;
			v.push_back(num);
		}
		else if (s == "pop_front")
		{
			if (!v.empty())
			{
				cout << v.front() << '\n';
				v.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (s == "pop_back")
		{
			if (!v.empty())
			{
				cout << v.back() << '\n';
				v.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (s == "size")
			cout << v.size() << '\n';

		else if (s == "empty")
			!v.empty() ? cout << 0 << '\n' : cout << 1 << '\n';

		else if (s == "front")
			!v.empty() ? cout << v.front() << '\n' : cout << -1 << '\n';

		else
			!v.empty() > 0 ? cout << v.back() << '\n' : cout << -1 << '\n';
	}
	return 0;
}