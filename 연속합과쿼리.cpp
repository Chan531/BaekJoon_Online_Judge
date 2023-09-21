#include <iostream>
#include <algorithm>
#define N 101010

using namespace std;

struct info {
   int val, lval, rval, sum;
};

int n, q, arr[N], INF = -1e9;
info tree[N * 4];

void input()
{
   cin >> n;

   for (int i = 1; i <= n; i++)
      cin >> arr[i];

   cin >> q;
}

void init(int s = 1, int e = n, int node = 1)
{
   if (s == e)
   {
      tree[node] = { arr[s], arr[s], arr[s], arr[s] };
      return;
   }

   int m = (s + e) / 2;
   init(s, m, node * 2);
   init(m + 1, e, node * 2 + 1);

   tree[node].val = max({ tree[node * 2].val, tree[node * 2 + 1].val, tree[node * 2].rval + tree[node * 2 + 1].lval });
   tree[node].lval = max(tree[node * 2].lval, tree[node * 2].sum + tree[node * 2 + 1].lval);
   tree[node].rval = max(tree[node * 2 + 1].rval, tree[node * 2 + 1].sum + tree[node * 2].rval);
   tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

info query(int s, int e, int node, int l, int r)
{
   if (s > r || e < l)
      return { INF, INF, INF, 0 };

   if (s >= l && e <= r)
      return tree[node];

   int m = (s + e) / 2;
      
   info left = query(s, m, node * 2, l, r);
   info right = query(m + 1, e, node * 2 + 1, l, r);
   return { max({left.val, right.val, left.rval + right.lval}), max(left.lval, left.sum + right.lval),  max(right.rval, right.sum + left.rval), left.sum + right.sum };
}

void solution()
{
   init();

   while (q--)
   {
      int a, b;
      cin >> a >> b;
      cout << query(1, n, 1, a, b).val << '\n';
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