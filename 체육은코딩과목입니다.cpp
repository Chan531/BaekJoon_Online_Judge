#include <iostream>

using namespace std;

int n = 10, a, b;

void input()
{

}

void solution()
{
    while (n--)
    {
        cin >> a;

        if (a == 1)
            b += 1;

        else if (a == 2)
            b += 2;

        else
            b -= 1;

        if (b == -1)
            b = 3;

        b %= 4;
    }

    if (b == 0)
        cout << 'N';

    else if (b == 1)
        cout << 'E';

    else if (b == 2)
        cout << 'S';

    else
        cout << 'W';
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