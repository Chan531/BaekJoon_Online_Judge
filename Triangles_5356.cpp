#include <iostream>

using namespace std;

int n;
char c;

void input()
{
    cin >> n >> c;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (c == 'Z' + 1) c = 'A';
        for (int j = 1; j <= i; j++) cout << c;
        cout << '\n';
        c++;
    }

    cout << '\n';
}

void solve()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        input();
        solution();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}