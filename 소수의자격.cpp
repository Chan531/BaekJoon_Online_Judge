#include <iostream>
#include <string>
#define N 4000000

using namespace std;

int a, b, prime[N + 1], ans = 0;
string d;

void input()
{
	cin >> a >> b >> d;
}

void solution()
{
	prime[1] = 1;
	for (int i = 2; i <= N; i++)
		if (!prime[i])
			for (int j = i * 2; j <= N; j += i)
				prime[j] = 1;

	for (int i = a; i <= b; i++)
	{
		if (prime[i])
			continue;

		string num = to_string(i);

		if (num.find(d) != string::npos)
			ans++;
	}

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