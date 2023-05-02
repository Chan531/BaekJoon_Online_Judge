#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string arr[1000];
unordered_map<string, bool> check;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int len = 1;
	int s = arr[0].length() - 1;

	for (int i = s; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[arr[j].substr(i, len)])
				break;

			check[arr[j].substr(i, len)] = 1;
		}

		if (check.size() == n)
			break;

		len++;
		check.clear();
	}

	cout << len;
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