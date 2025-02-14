#include <iostream>

using namespace std;

int n, r, c, idx;
string s;
char map[101][101];

void input()
{
    cin >> s;
}

void solution()
{
    n = s.length();

    for (int i = 1; i <= n; i++)
    {
        if (n % i) continue;
        if (r < i && i <= n / i)
        {
            r = i;
            c = n / i;
        }
    }

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            map[j][i] = s[idx++];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cout << map[i][j];
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