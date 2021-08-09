#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, p = 0, c = 0;
	vector<int> v;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			v.push_back(num);
			c++;
		}
		else if (s == "pop")
		{
			if (c - p == 0)
				cout << -1 << '\n';
			else
			{
				cout << v[p] << '\n';
				p++;
			}
		}
		else if (s == "size")
			cout << c - p << '\n';

		else if (s == "empty")
			c - p == 0 ? cout << 1 << '\n' : cout << 0 << '\n';

		else if (s == "front")
			c - p == 0 ? cout << -1 << '\n' : cout << v[p] << '\n';

		else
			c - p == 0 ? cout << -1 << '\n' : cout << v[c - 1] << '\n';
	}
	return 0;
}