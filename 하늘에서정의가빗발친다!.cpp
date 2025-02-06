#include <iostream>
#include <cmath>
#include <algorithm>
#define p pair<double, int>

using namespace std;

int n;
double arr[101010][3];
p ans[101010];

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        ans[i] = { sqrt(arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1]) / arr[i][2], i + 1 };
    }

    sort(ans, ans + n);

    for (int i = 0; i < n; i++)
        cout << ans[i].second << '\n';
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