#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, b, num, time, ans = 1e9, h;
vector<int> arr;


void input()
{
    cin >> n >> m >> b;
    for (int i = 0; i < n * m; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
}

void solution()
{
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = arr[n * m - 1]; i <= arr[0]; i++)
    {
        int block = b;
        time = 0;

        for (int j = 0; j < n * m; j++)
        {
            if (arr[j] == i)
                continue;

            else if (arr[j] > i)
            {
                time += (arr[j] - i) * 2;
                block += arr[j] - i;
            }

            else
            {
                time += i - arr[j];
                block -= i - arr[j];

                if (block < 0)
                {
                    time = 1e9;
                    break;
                }
            }
        }

        if (ans >= time)
        {
            ans = time;
            h = i;
        }
    }
    cout << ans << ' ' << h;
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