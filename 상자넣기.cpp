#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	cin >> n;
	vector<int> v, w(n, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				w[i] = max(w[i], w[j] + 1);
		}
	}
	cout << *max_element(w.begin(), w.end());
	return 0;
}