#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v, w;
		for (int j = 0; j < 2 * n; j++)
		{
			cin >> num;
			if (j < n)
				v.push_back(num);
			else
				w.push_back(num);
		}
		v[1] += w[0];
		w[1] += v[0];
		for (int i = 2; i < n; i++)
		{
			v[i] += max(w[i - 1], w[i - 2]);
			w[i] += max(v[i - 1], v[i - 2]);
		}
		cout << max(w[n - 1], v[n - 1]) << '\n';
	}
	return 0;
}