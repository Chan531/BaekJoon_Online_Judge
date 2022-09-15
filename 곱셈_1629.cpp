#include <iostream>

using namespace std;

long long mul(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;

    long long mult = mul(a, b / 2, c);

    if (!(b % 2))
        return mult % c * mult % c;

    else
        return mult % c * mult % c * (a % c) % c;
}

int main(void)
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << mul(a % c, b, c);
    return 0;
}

// 2022.09.15 Ç®ÀÌ
/*
#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

long long mul(int n)
{
	if (n == 1)
		return a % c;

	if (n % 2)
		return mul(n / 2) * mul(n / 2 + 1) % c;

	else
		return mul(n / 2) * mul(n / 2) % c;
}

void solution()
{
	cout << mul(b);
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
*/