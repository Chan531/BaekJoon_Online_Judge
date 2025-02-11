#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 202020
#define p pair<int, long long>

using namespace std;

struct cmp {
    bool operator()(p a, p b) {
        return a.second > b.second;
    }
};

int n, m, a, b;
vector<p> v[N];
vector<int> ans;
long long dp[N];
priority_queue<p, vector<p>, cmp> pq;
bool visited[N];

void input()
{
    cin >> n >> m >> a >> b;

    while (m--)
    {
        int s, e;
        long long d;
        cin >> s >> e >> d;
        v[s].push_back({ e, d });
        v[e].push_back({ s, d });
    }
}

void init()
{
    for (int i = 1; i <= n; i++) dp[i] = 1e16;
    dp[a] = 0;
}

void dfs(int k)
{
    if (visited[k] || a == k) return;

    visited[k] = 1;
    ans.push_back(k);

    for (int i = 0; i < v[k].size(); i++)
        if (dp[k] - v[k][i].second == dp[v[k][i].first])
            dfs(v[k][i].first);
}

void solution()
{
    init();
    pq.push({ a, 0 });

    while (!pq.empty())
    {
        int cur = pq.top().first;
        long long val = pq.top().second;
        pq.pop();

        if (val > dp[cur]) continue;

        if (cur == b) continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            long long nval = val + v[cur][i].second;

            if (nval >= dp[next]) continue;
            dp[next] = nval;
            pq.push({ next, nval });
        }
    }

    for (int i = 0; i < v[b].size(); i++)
    {
        if (dp[b] - v[b][i].second == dp[v[b][i].first])
            dfs(v[b][i].first);
    }

    ans.push_back(a);
    ans.push_back(b);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
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