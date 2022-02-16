#include <iostream>
#include <string>

using namespace std;

int n, l, idx, num;
string line;

int check(int n)
{
	if (n == 9)
		return 2;

	else if (n == 99)
		return 3;

	else
	{
		string s = to_string(n);
		return (int)s.length();
	}
}

void solve()
{
	cin >> line;
	for (int i = 1; i <= 3; i++)
	{
		n = stoi(line.substr(0, i));
		idx = i;

		l = check(n);

		while (idx < line.length())
		{
			num = stoi(line.substr(idx, l));

			if (n + 1 != num)
				break;

			idx += l;
			l = check(num);
			n = num;
		}

		if (idx == line.length())
		{
			cout << line.substr(0, i) << ' ' << n;
			break;
		}
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