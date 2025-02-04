#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
long long vsum, wsum;
vector<long long> v, w;

void input()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        v.push_back(m);
        vsum += m;
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        w.push_back(m);
        wsum += m;
    }
}

void solution()
{
    for (int i = 0; i < k; i++)
    {
        if (vsum > wsum)
        {
            vsum -= v.back();
            v.pop_back();
        }

        else
        {
            wsum -= w.back();
            w.pop_back();
        }
    }

    cout << max(vsum, wsum);
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