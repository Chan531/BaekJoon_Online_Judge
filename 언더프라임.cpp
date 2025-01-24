#include <iostream>
#include <vector>

using namespace std;

int a, b, ans;
vector<int> v, w;
bool check[101010];

void input()
{
    cin >> a >> b;
}

void init()
{
    check[1] = 1;

    for (int i = 2; i <= 100000; i++)
    {
        if (check[i]) continue;
        v.push_back(i);

        for (int j = i * 2; j <= 100000; j += i) check[j] = 1;
    }
}

void solution()
{
    init();

    for (int i = a; i <= b; i++)
    {
        int temp = i;
        for (auto k : v)
        {
            while (temp != 1 && temp % k == 0)
            {
                w.push_back(k);
                temp /= k;
            }
        }
        if (!check[w.size()]) ans++;
        w.clear();
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