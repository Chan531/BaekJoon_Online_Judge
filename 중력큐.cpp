#include <iostream>
#include <deque>

using namespace std;

int n, cur, bcnt, wcnt;
deque<int> dq;

void input()
{
    cin >> n;
}

void cal(int m)
{
    m == 1 ? bcnt-- : wcnt--;
}

void solution()
{
    while (n--)
    {
        string s;
        cin >> s;

        if (s == "pop")
        {
            if (dq.empty()) continue;
            cal(dq.front());
            dq.pop_front();

            if (cur == 1)
            {
                while (!dq.empty() && dq.front() != 2)
                {
                    bcnt--;
                    dq.pop_front();
                }
            }

            continue;
        }

        char c;
        cin >> c;

        if (s == "push")
        {
            if (c == 'b')
            {
                if (cur == 3 || (cur == 1 && dq.empty())) continue;
                dq.push_back(1);
                bcnt++;
            }

            else
            {
                dq.push_back(2);
                wcnt++;
            }
        }

        else if (s == "rotate")
        {
            if (c == 'l')
            {
                cur--;
                if (cur == -1) cur = 3;

                if (cur == 1)
                {
                    while (!dq.empty() && dq.front() != 2)
                    {
                        bcnt--;
                        dq.pop_front();
                    }
                }

                else if (cur == 3)
                {
                    while (!dq.empty() && dq.back() != 2)
                    {
                        bcnt--;
                        dq.pop_back();
                    }
                }
            }

            else
            {
                cur++;
                cur %= 4;

                if (cur == 1)
                {
                    while (!dq.empty() && dq.front() != 2)
                    {
                        bcnt--;
                        dq.pop_front();
                    }
                }

                else if (cur == 3)
                {
                    while (!dq.empty() && dq.back() != 2)
                    {
                        bcnt--;
                        dq.pop_back();
                    }
                }
            }
        }

        else if (s == "count")
        {
            if (c == 'b') cout << bcnt << '\n';
            else cout << wcnt << '\n';
        }
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