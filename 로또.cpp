#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		vector<int> v;
		vector<int> w(n);
		for (int i = 0; i < 6; i++)
			w[i] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < 6; i++)
			cout << v[i] << ' ';
		cout << '\n';
		while (prev_permutation(w.begin(), w.end()))
		{
			for (int i = 0; i < n; i++)
			{
				if (w[i] == 1)
					cout << v[i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}