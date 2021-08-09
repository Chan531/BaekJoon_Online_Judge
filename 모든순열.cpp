#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fac(int n)
{
	int f = 1;
	while (n != 1)
	{
		f *= n;
		n--;
	}
	return f;
}

int main(void)
{
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < fac(n); i++)
	{
		for (auto i : v)
		{
			cout << i << ' ';
		}
		cout << '\n';
		next_permutation(v.begin(), v.end());
	}
	return 0;
}