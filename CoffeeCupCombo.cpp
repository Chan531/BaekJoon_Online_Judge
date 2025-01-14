#include <iostream>

using namespace std;

int n, ans, cnt;

void input()
{
    cin >> n;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c == '1')
        {
            ans++;
            cnt = 2;
        }

        else
        {
            if (cnt)
            {
                ans++;
                cnt--;
            }
        }
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