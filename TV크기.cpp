#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int d, h, w;
	cin >> d >> h >> w;
	double k = sqrt(pow(d, 2) / (pow(h, 2) + pow(w, 2)));
	cout << int(h * k) << ' ' << int(w * k);
	return 0;
}