#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double arr[10000], ans;

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	cout << fixed;
	cout.precision(4);

	double cur = 1;

	for (int i = 0; i < n; i++)
	{
		cur *= arr[i];
		
		ans = max(ans, cur);

		if (cur < 1)
			cur = 1;
	}

	ans *= 1000;
	round(ans);
	cout.precision(3);
	cout << ans / 1000;
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