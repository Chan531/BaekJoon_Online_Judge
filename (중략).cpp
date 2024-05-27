#include <iostream>
#include <string>

using namespace std;

int n, arr[101010];
string s, ans;

void input()
{
	cin >> n >> s;
}

void solution()
{
	// Rule 1
	if (n <= 25)
	{
		cout << s;
		return;
	}

	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i] = idx;

		if (s[i] == '.')
			idx++;
	}

	// Rule 2
	if (arr[11] == arr[n - 12])
		cout << s.substr(0, 11) << "..." << s.substr(n - 11, 11);

	// Rule 3
	else
		cout << s.substr(0, 9) << "......" << s.substr(n - 10, 10);
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}