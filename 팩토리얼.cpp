#include <iostream>

using namespace std;

int multi(int i)
{
    if (i == 0)
        return 1;
    return i * multi(i - 1);
}

int main(void)
{
    int n = 0;
    cin >> n;
    cout << multi(n);
}