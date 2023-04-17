#include <iostream>
#include <cmath>
#define ull unsigned long long
#define K 64

using namespace std;

int k;
ull a, b, ans;
ull acnt[K][2], bcnt[K][2], val[K];


void input()
{
	cin >> a >> b;
}

void init()
{
	val[0] = 1;
	k = log2(b) + 1;

	for (int i = 1; i <= k; i++)
		val[i] = val[i - 1] * 2;
}

void count_a(ull n)
{
	acnt[0][1] = (n + 1) / 2;
	acnt[0][0] = n - acnt[0][1];

	for (int i = 1; i < k; i++)
	{
		if (n < val[i])
			acnt[i][1] = 0;

		else if ((n - val[i]) % val[i + 1] >= val[i])
			acnt[i][1] = (n - val[i]) / val[i + 1] * val[i] + val[i];

		else
			acnt[i][1] = (n - val[i]) / val[i + 1] * val[i] + (n % val[i]) + 1;

		acnt[i][0] = n - acnt[i][1];
	}
}

void count_b(ull n)
{
	bcnt[0][1] = (n + 1) / 2;
	bcnt[0][0] = n - bcnt[0][1];

	for (int i = 1; i < k; i++)
	{
		if (n < val[i])
			bcnt[i][1] = 0;

		else if ((n - val[i]) % val[i + 1] >= val[i])
			bcnt[i][1] = (n - val[i]) / val[i + 1] * val[i] + val[i];

		else
			bcnt[i][1] = (n - val[i]) / val[i + 1] * val[i] + (n % val[i]) + 1;

		bcnt[i][0] = n - bcnt[i][1];
	}
}

void solution()
{
	init();
	count_a(a - 1);
	count_b(b);

	for (int i = 0; i < k; i++)
	{
		bcnt[i][0] -= acnt[i][0];
		bcnt[i][1] -= acnt[i][1];
	}

	for (int i = 0; i < k; i++)
		if (bcnt[i][1] % 2)
			ans += val[i];

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