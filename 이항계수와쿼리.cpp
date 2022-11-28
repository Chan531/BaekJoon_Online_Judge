#include <iostream>
#define N 4000001
#define mod 1000000007
#define ll long long

using namespace std;

int m;
ll n, k, ans;
ll nume[N], deno[N];

void input()
{
	cin >> m;
}

ll mul(ll a, ll b)
{
	if (b == 1)
		return a;

	ll sroot = mul(a, b / 2) % mod;

	if (b % 2)
		return ((sroot * sroot) % mod) * a % mod;

	else
		return sroot * sroot % mod;
}

void solution()
{
	ll cnt = 1;

	// 분자 기록
	for (int i = 1; i < N; i++)
	{
		cnt *= i;
		cnt %= mod;
		nume[i] = cnt;
	}

	cnt = 1;

	// 분모 기록
	for (int i = 1; i < N; i++)
	{
		cnt *= mul(i, mod - 2);
		cnt %= mod;
		deno[i] = cnt;
	}

	while (m--)
	{
		cin >> n >> k;

		cout << ((nume[n] * deno[k]) % mod) * deno[n - k] % mod;
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
	cout.tie(NULL);

	solve();
	return 0;
}