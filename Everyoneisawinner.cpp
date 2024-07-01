#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    if (a % b) cout << "No";
    else cout << "Yes";
    return 0;
}