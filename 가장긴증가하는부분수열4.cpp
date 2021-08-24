#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, sta;
	vector<int> v, k;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		sta = v[i];
		for (int j = 0; j < i; j++)
		{
			if (sta > v[j])
			{
				w[i] = max(w[i], w[j] + 1);
			}
		}
	}
	sta = *max_element(w.begin(), w.end());
	cout << sta + 1 << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		if (w[i] == sta)
		{
			k.push_back(v[i]);
			sta--;
		}
	}
	for (int i = k.size() - 1; i >= 0; i--)
		cout << k[i] << ' ';
	return 0;
}