#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(10000001);
	v[1]++;
	vector<int> p;
	int n, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 1)
		{

		}
		else
		{
			while (n % i == 0)
			{
				n /= i;
				p.push_back(i);
			}
			for (int j = i * 2; j <= n; j += i)
			{
				v[j] = 1;
			}
		}
	}
	for (auto i : p)
		cout << i << '\n';
	return 0;
}