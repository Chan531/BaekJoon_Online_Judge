#include <iostream>
#include <algorithm>
#include <numeric>
#define N 1010

using namespace std;

int b, c, d, B[N], C[N], D[N], ans;

void input()
{
	cin >> b >> c >> d;

	for (int i = 0; i < b; i++)
		cin >> B[i];

	for (int i = 0; i < c; i++)
		cin >> C[i];

	for (int i = 0; i < d; i++)
		cin >> D[i];
}

void solution()
{
	sort(B, B + b, greater<int>());
	sort(C, C + c, greater<int>());
	sort(D, D + d, greater<int>());

	cout << accumulate(B, B + b, 0) + accumulate(C, C + c, 0) + accumulate(D, D + d, 0) << '\n';

	int idx = min({ b,c,d });

	for (int i = 0; i < idx; i++)
	{
		int val = 0;
		val += B[i] + C[i] + D[i];
		ans += val / 10 * 9;
	}

	for (int i = idx; i < b; i++)
		ans += B[i];

	for (int i = idx; i < c; i++)
		ans += C[i];

	for (int i = idx; i < d; i++)
		ans += D[i];

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