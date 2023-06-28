#include <iostream>
#include <cmath>
#define N 1010

using namespace std;

double n, cnt, arr[N], sum, avg;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
}

void solution()
{
	avg = sum / n;
	for (int i = 0; i < n; i++) if (arr[i] > avg) cnt++;
	cout << (cnt / n) * 100 << "%\n";
	sum = 0;
	cnt = 0;
}

void solve()
{
	cout << fixed;
	cout.precision(3);

	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}