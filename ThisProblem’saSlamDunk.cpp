#include <iostream>
#include <algorithm>

using namespace std;

int a[5], b[5], ans;

void input()
{
	for (int i = 0; i < 5; i++)
		cin >> a[i];

	for (int i = 0; i < 5; i++)
		cin >> b[i];
}

void solution()
{
	sort(a, a + 5);
	sort(b, b + 5);

	for (int i = 0; i < 5; i++)
		if (a[i] > b[i])
			ans++;

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
	cout.tie(NULL);

	solve();
	return 0;
}