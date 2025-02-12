#include <iostream>
#include <vector>
#include <cstring>
#define N 101010

using namespace std;

int n, k, arr[N], par[N];
vector<int> v[N];
bool visited[N];

void init()
{
    memset(par, -1, sizeof(par));
}

void input()
{
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int p, c;
        cin >> p >> c;
        v[p].push_back(c);
        par[c] = p;
    }

    for (int i = 0; i < n; i++) cin >> arr[i];
}

int dfs(int m, int c)
{
    int ret = 0;
    if (c > k) return ret;

    for (int i = 0; i < v[m].size(); i++)
    {
        if (visited[v[m][i]]) continue;
        visited[v[m][i]] = 1;
        ret += dfs(v[m][i], c + 1);
    }

    if (arr[m]) return ret + 1;
    return ret;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        if (par[i] != -1) continue;
        visited[i] = 1;
        cout << dfs(i, 0);
        break;
    }
}

void solve()
{
    init();
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