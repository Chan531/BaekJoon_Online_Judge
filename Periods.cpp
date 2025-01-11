#include <iostream>
#include <string>

using namespace std;

int n;

void input()
{
    cin >> n;
    cin.ignore();
}

void solution()
{
    while (n--)
    {
        string s;
        getline(cin, s);
        cout << s;
        if (s[s.length() - 1] != '.')
            cout << '.';
        cout << '\n';
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