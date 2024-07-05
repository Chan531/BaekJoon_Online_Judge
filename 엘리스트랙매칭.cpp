#include <iostream>

using namespace std;

int n, ans;
char c, arr[10100];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> c;
    for (int i = 0; i < n; i++)
        if (arr[i] == c)
            ans++;
    cout << ans;
    return 0;
}