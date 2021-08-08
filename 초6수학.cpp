#include <iostream>

using namespace std;

int gcd(int a, int b) {

    if (b == 0) 
        return a;

    else 
        return gcd(b, a % b);
}

int main(void)
{
	int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int min = gcd(n, m);
        cout << n / min * m / min * min << ' ' << min <<'\n';
    }
	return 0;
}