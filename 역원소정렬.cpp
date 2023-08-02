#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
long long arr[1000001];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		reverse(s.begin(), s.end());
		arr[i] = stoull(s);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
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