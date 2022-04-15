#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x, a, b, dist[300001];
vector<int> connect[300001];

struct node {
    int dis, pos;
};

void input()
{
    cin >> n >> m >> k >> x;
    while (m--)
    {
        cin >> a >> b;
        connect[a].push_back(b);
    }
}

void solution()
{
    queue<node> q;
    q.push({ 1, x });
    dist[x] = -1;

    while (!q.empty())
    {
        int dis = q.front().dis;
        int pos = q.front().pos;
        q.pop();

        for (int i = 0; i < connect[pos].size(); i++)
        {
            int npos = connect[pos][i];

            if (dist[npos])
                continue;

            dist[npos] = dis;
            q.push({ dis + 1, npos });
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == k)
        {
            cout << i << '\n';
            cnt++;
        }
    }

    if (!cnt)
        cout << -1;
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
    cout.tie(NULL);

    solve();
    return 0;
}