#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n, x, y, answer = 0;
	cin >> n;
	vector<pair<int, int>> v(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v[i] = { x,y };
	}
	v[n] = v[0];
	for (int i = 0; i < n; i++)
		answer += sqrt(pow(v[i].first - v[i + 1].first, 2) + pow(v[i].second - v[i + 1].second, 2));
	cout << answer;
	return 0;
}