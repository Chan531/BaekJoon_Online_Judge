#include <iostream>

using namespace std;

int n, m;

void input()
{
    cin >> n >> m;
}

void solution()
{
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((i * i + j * j + m) % (i * j)) continue;
            ans++;
        }
    }

    cout << ans << '\n';
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