#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, nf = 0, mf = 0, nmf = 0, nt = 0, mt = 0, nmt = 0;
	long long f = 5, t = 2;
	cin >> n >> m;

	while (n / f != 0)
	{
		nf += n / f;
		f *= 5;
	}
	while (n / t != 0)
	{
		nt += n / t;
		t *= 2;
	}
	f = 5;
	t = 2;
	while (m / f != 0)
	{
		mf += m / f;
		f *= 5;
	}
	while (m / t != 0)
	{
		mt += m / t;
		t *= 2;
	}
	f = 5;
	t = 2;
	while ((n - m) / f != 0)
	{
		nmf += (n - m) / f;
		f *= 5;
	}
	while ((n - m) / t != 0)
	{
		nmt += (n - m) / t;
		t *= 2;
	}
	cout << min(nf - mf - nmf, nt - mt - nmt);
	return 0;
}