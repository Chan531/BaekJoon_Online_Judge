#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, l = 1, r = 1, ll, rr;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	ll = v[0];
	rr = v[n - 1];
	for (int i = 1; i < n; i++)
	{
		if (ll < v[i])
		{
			l++;
			ll = v[i];
		}
		if (rr < v[n - i - 1])
		{
			r++;
			rr = v[n - i - 1];
		}
	}
	cout << l << '\n' << r;
	return 0;
}