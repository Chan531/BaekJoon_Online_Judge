#include <iostream>

using namespace std;

int n, ans;
char c[101010];

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++) cin >> c[i];
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (c[i] == a) ans++;
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

    solve();
    return 0;
}