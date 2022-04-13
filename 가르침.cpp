#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, k, alp[21], ans = 0;
string word[50];
char alpha[21] = { 'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z' };
map<char, int> idx;

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> word[i];
}

bool know(char c)     // 알고 있는 글자인지 판별
{
    if (c == 'a' || c == 'c' || c == 'i' || c == 'n' || c == 't' || alp[idx[c]])
        return true;

    return false;
}

void check()         // 알고 있는 글자로 몇 개의 단어를 알 수 있는지 판별
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int len = word[i].length();
        for (int j = 3; j < len - 4; j++)
        {
            if (!know(word[i][j]))    // 한 글자라도 모른다면 out
                break;

            if (j == len - 5)         // 모든 글자를 안다면 cnt++
                cnt++;
        }
    }
    ans = max(ans, cnt);
}

void solution()
{
    if (k < 5)
    {
        cout << 0;
        return;
    }

    k -= 5;              // a, c, i, n, t는 무조건 알아야하므로

    for (int i = 0; i < k; i++)
        alp[i] = 1;

    for (int i = 0; i < 21; i++)    // 글자 idx 기록
        idx[alpha[i]] = i;

    do {
        check();
    } while (prev_permutation(alp, alp + 21));

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
    cout.tie(NULL);

    solve();
    return 0;
}