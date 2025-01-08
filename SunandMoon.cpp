#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{
    cin >> a >> b >> c >> d;
}

void solution()
{
    int ad = b - a;
    int cd = d - c;

    while (1)
    {
        if (ad == cd) break;

        if (ad < cd) ad += b;
        else cd += d;
    }

    cout << ad;
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