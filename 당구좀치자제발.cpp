#include <iostream>

using namespace std;

int n, m;
long long ans, cur;

int main(void)
{
    cin >> n;

    while (n--)
    {
        cin >> m;
        if (m) cur++;
        else cur--;
        ans += cur;
    }

    cout << ans;
    return 0;
}