#include <iostream>

using namespace std;

int n, ans;

int main(void)
{
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;
        ans += (m + 1) / 2;
    }

    cout << ans;
    return 0;
}