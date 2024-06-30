#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[26];
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n; i++)
		arr[s[i] - 'A']++;

	cout << min({ arr[0], arr[2], arr[7], arr[8], arr[17] });
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