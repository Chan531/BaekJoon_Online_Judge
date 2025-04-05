#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    if (s == "1") cout << 1;
    else if (s == "12") cout << 2;
    else if (s == "123") cout << 3;
    else if (s == "1234") cout << 4;
    else if (s == "12345") cout << 5;
    else if (s == "123456") cout << 6;
    else if (s == "1234567") cout << 7;
    else if (s == "12345678") cout << 8;
    else if (s == "123456789") cout << 9;
    else cout << -1;

    return 0;
}