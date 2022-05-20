#include <iostream>

using namespace std;

void solve()
{
	string a, b;

	while (1)
	{
		cin >> a >> b;

		if (cin.eof())
			break;

		int idx = 0;
		for (int i = 0; i < b.length(); i++)
		{
			if (idx == a.length())
				break;

			if (a[idx] == b[i])
				idx++;
		}

		idx == a.length() ? cout << "Yes\n" : cout << "No\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}