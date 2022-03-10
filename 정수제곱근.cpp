#include <iostream>
#include <cmath>
#define ull unsigned long long

using namespace std;

ull n;

void input()
{
	cin >> n;
}

void solution()
{
	ull start = 1, end = n, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (mid >= sqrt(n))
			end = mid - 1;
		else
			start = mid + 1;
	}
	while (mid * mid < n) mid++;
	cout << mid;
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