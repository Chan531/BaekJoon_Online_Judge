#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

void input()
{
    cin >> n >> k;
}

void solution()
{
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (1)
    {
        if (q.size() <= k) break;

        int m = q.front();
        q.pop();

        for (int i = 1; i < k; i++)
            q.pop();

        q.push(m);
    }

    cout << q.front();
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