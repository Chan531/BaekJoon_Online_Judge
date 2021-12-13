#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a, x, y;

bool absev(int a)
{
	return a >= y;
}

int main(void)
{
	vector<int> score;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		score.push_back(a);
	}
	cin >> x >> y;
	cout << x * n / 100 << ' ' << count_if(score.begin(), score.end(), absev);
	return 0;
}