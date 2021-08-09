#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, six, one;
	vector<int> s;
	vector<int> o;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> six >> one;
		s.push_back(six);
		o.push_back(one);
	}
	int mins = *min_element(s.begin(), s.end());
	int mino = *min_element(o.begin(), o.end());
	int ms = (n / 6 + 1) * mins;
	int mo = (ms - mins) + ((n % 6) * mino);
	if (n * mino < mo)
		mo = n * mino;
	ms > mo ? cout << mo : cout << ms;
	return 0;
}