#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, sta;
	vector<int> v;
	cin >> n;
	vector<int> w(n + 1);
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
				w[i] = max(w[i], w[j] + 1);
		}
	}
	cout << *max_element(w.begin(), w.end()) + 1;
	return 0;
}