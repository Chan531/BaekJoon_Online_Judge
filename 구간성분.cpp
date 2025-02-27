#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

string s, t;
int sl, tl, sc[1515][26], tc[1515][26];

void input()
{
    cin >> s >> t;
}

void init()
{
    if (s.length() > t.length()) swap(s, t);

    sl = s.length();
    tl = t.length();

    for (int i = 1; i <= sl; i++)
    {
        for (int j = 0; j < 26; j++)
            sc[i][j] = sc[i - 1][j];

        sc[i][s[i - 1] - 'a']++;
    }

    for (int i = 1; i <= tl; i++)
    {
        for (int j = 0; j < 26; j++)
            tc[i][j] = tc[i - 1][j];

        tc[i][t[i - 1] - 'a']++;
    }
}

void solution()
{
    init();

    for (int i = sl; i; i--)
    {
        set<vector<int>> se;

        for (int j = 0; j <= sl - i; j++)
        {
            vector<int> v;

            for (int k = 0; k < 26; k++)
                v.push_back(sc[i + j][k] - sc[j][k]);

            se.insert(v);
        }

        for (int j = 0; j <= tl - i; j++)
        {
            vector<int> v;

            for (int k = 0; k < 26; k++)
                v.push_back(tc[i + j][k] - tc[j][k]);

            if (se.find(v) != se.end())
            {
                cout << i;
                return;
            }
        }
    }

    cout << 0;
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