#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[3];
string ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		char c;
		cin >> c;

		if (c == 'B') arr[0]++;
		else if (c == 'S') arr[1]++;
		else arr[2]++;
	}

	int val = max({ arr[0], arr[1], arr[2] });
	
	if (arr[0] == val) ans += 'B';
	if (arr[1] == val) ans += 'S';
	if (arr[2] == val) ans += 'A';
	if (ans == "BSA") ans = "SCU";

	cout << ans;
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