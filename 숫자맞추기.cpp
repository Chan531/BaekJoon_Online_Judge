#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
string s;
bool check[11];

void solve()
{
	while (1)
	{
		cin >> n;

		if (!n)
			break;

		cin.ignore();
		getline(cin, s);

		if (s == "right on")
		{
			if (check[n])
				cout << "Stan is dishonest\n";

			else
				cout << "Stan may be honest\n";

			memset(check, 0, sizeof(check));
			continue;
		}

		if (s == "too high")
			for (int i = n; i <= 10; i++)
				check[i] = 1;

		else if (s == "too low")
			for (int i = n; i > 0; i--)
				check[i] = 1;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}