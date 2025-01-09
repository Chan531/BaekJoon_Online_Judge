#include <iostream>
#include <algorithm>
#define N 101010
#define p pair<int, int>

using namespace std;

int n, m, arr[N], tree[N * 4][2];

void input()
{
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void init(int s, int e, int node)
{
    if (s == e)
    {
        tree[node][0] = arr[s];
        return;
    }

    int m = (s + e) / 2;
    init(s, m, node * 2);
    init(m + 1, e, node * 2 + 1);
    tree[node][0] = max(tree[node * 2][0], tree[node * 2 + 1][0]);
    tree[node][1] = max({ min(tree[node * 2][0], tree[node * 2 + 1][0]), tree[node * 2][1], tree[node * 2 + 1][1] });
}

void update(int s, int e, int node, int idx, int val)
{
    if (s > idx || e < idx) return;

    if (s == e && s == idx)
    {
        tree[node][0] = val;
        return;
    }

    int m = (s + e) / 2;
    update(s, m, node * 2, idx, val);
    update(m + 1, e, node * 2 + 1, idx, val);
    tree[node][0] = max(tree[node * 2][0], tree[node * 2 + 1][0]);
    tree[node][1] = max({ min(tree[node * 2][0], tree[node * 2 + 1][0]), tree[node * 2][1], tree[node * 2 + 1][1] });
}

int cal(p val)
{
    return val.first + val.second;
}

p output(int s, int e, int node, int l, int r)
{
    if (s > r || e < l) return { 0, 0 };

    if (s >= l && e <= r)
        return { tree[node][0], tree[node][1] };

    int m = (s + e) / 2;
    p lv = output(s, m, node * 2, l, r);
    p rv = output(m + 1, e, node * 2 + 1, l, r);
    int first = max({ lv.first, rv.first });
    int second = max({ min(lv.first, rv.first), lv.second, rv.second });
    return { first, second };
}

void solution()
{
    init(1, n, 1);
    cin >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) update(1, n, 1, b, c);
        else cout << cal(output(1, n, 1, b, c)) << '\n';
    }
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