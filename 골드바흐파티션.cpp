#include <iostream>
#include <vector>

using namespace std;
vector<int> v(1000001), w;

int checkcnt(int n)
{
	int cnt = 0, j = 0;
	while (w[j] <= n / 2)
	{
		if (!v[n - w[j++]])
			cnt++;
	}
	return cnt;
}

int main(void)
{
	int n, num;
	v[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!v[i])
		{
			w.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i)
				v[j] = 1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << checkcnt(num) << '\n';
	}
	return 0;
}