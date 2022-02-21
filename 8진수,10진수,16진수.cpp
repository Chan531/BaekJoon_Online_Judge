#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string x;
int ans = 0, idx, mul = 0;

int check(string x)
{
	if (x[0] != '0')
		ans = stoi(x);

	else if (x[1] == 'x')
	{
		idx = x.length() - 1;
		for (int i = idx; i >= 2; i--)
		{
			if (isdigit(x[i]))
				ans += pow(16, mul) * (x[i] - '0');
			else
				ans += pow(16, mul) * (x[i] - 'W');
			mul++;
		}
	}

	else
	{
		idx = x.length() - 1;
		for (int i = idx; i >= 1; i--)
			ans += pow(8, mul++) * (x[i] - '0');
	}

	return ans;
}

void solve()
{
	cin >> x;
	cout << check(x);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}