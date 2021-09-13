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