#include <iostream>

using namespace std;

int p;
long long fibo[10101], q;

void input()
{
	cin >> p >> q;
}

void solution()
{
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i <= p; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % q;
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		cout << "Case #" << i << ": " << fibo[p] % q<< '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}