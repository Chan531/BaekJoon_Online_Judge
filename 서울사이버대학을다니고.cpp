#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, arr[26], ans;
string s;

int main(void) {
    cin >> n;
    cin.ignore();
    getline(cin, s);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i])) arr[s[i] - 'a']++;
        ans = max(ans, arr[s[i] - 'a']);
    }

    cout << ans;
    return 0;
}