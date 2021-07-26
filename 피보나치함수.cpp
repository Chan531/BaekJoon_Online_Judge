#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> v(41);

int fibo(int n)
{
	v[0] = make_pair(1, 0);
	v[1] = make_pair(0, 1);
	for (int i = 2; i <= n; i++)
	{
		v[i] = make_pair(v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second);
	}
	return 0;
}

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		fibo(num);
		cout << v[num].first << ' ' << v[num].second << '\n';
	}
	return 0;
}