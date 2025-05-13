#include <iostream>

using namespace std;

string s, t;
bool check[26];

int main(void) {
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) check[s[i] - 'a'] = 1;
    for (int i = 0; i < t.length(); i++) if (!check[t[i] - 'a']) cout << t[i];
    return 0;
}