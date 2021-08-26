#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n, x, y; 
	double answer = 0;
	vector<long long> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(x);
		v.push_back(y);
	}
	v.push_back(v[0]);
	v.push_back(v[1]);
	for (int i = 3; i <= 2 * n + 1; i += 2)
		answer += v[i] * v[i - 3];
	for (int i = 2; i <= 2 * n; i += 2)
		answer -= v[i] * v[i - 1];
	answer = abs(answer / 2);
	answer *= 10;
	answer = round(abs(answer));
	cout << fixed;
	cout.precision(1);
	cout << answer / 10;
	return 0;
}