#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count;
	vector<int> v(1000001);
	vector<int> w;
	for (int i = 2; i < 1000000; i++)
	{
		if (v[i] == 0)
		{
			w.push_back(i);
			for (int j = i * 2; j < 1000000; j += i)
				v[j] = 1;
		}
	}
	while (1)
	{
		count = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < w.size(); i++)
		{
			if (v[n - w[i]] == 0)
			{
				cout << n << " = " << w[i] << " + " << n - w[i];
				count = 1;
				break;
			}
		}
		if (count == 0)
			"Goldbach's conjecture is wrong.";
		cout << '\n';
	}
	return 0;
}