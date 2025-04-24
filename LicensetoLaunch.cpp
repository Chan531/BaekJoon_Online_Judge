#include <iostream>

using namespace std;

int n, ans, val = 1e9;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        if (k < val)
        {
            ans = i;
            val = k;
        }
    }

    cout << ans;

    return 0;
}