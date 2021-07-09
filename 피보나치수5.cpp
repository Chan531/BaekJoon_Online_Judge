#include <iostream>

using namespace std;

int fibo(int i)
{
    if (i == 0)
        return 0;

    if (i == 1)
        return 1;

    return fibo(i - 1) + fibo(i - 2);
}

int main(void)
{
    int n = 0;
    cin >> n;
    cout << fibo(n);
}