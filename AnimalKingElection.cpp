#include <iostream>

using namespace std;

int n, m;

int main(void) {
    string s;
    for (int i = 0; i < 9; i++)
    {
        cin >> s;
        if (s == "Lion") n++;
        else m++;
    }
    if (n > m) cout << "Lion";
    else cout << "Tiger";
    return 0;
}