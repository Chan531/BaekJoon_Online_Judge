#include <iostream>
#include <unordered_map>
#include <string>

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
	for (int i = 0; i < n; i++)
	{
		string temp = arr[i];
		check[temp] = 1;

		for (int j = i + 1; j < n; j++)
		{
			temp += arr[j];
			check[temp] = 1;
		}
	}

	for (int i = 0; ; i++)
	{
		string temp = to_string(i);

		if (!check[temp])
		{
			cout << temp;
			break;
		}
	}
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