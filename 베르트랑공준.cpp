#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(246913);

int main(void)
{
	int n;
	vector<int> w;
	v[1]++;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		w.push_back(n);
	}
	int max = *max_element(w.begin(), w.end()) * 2;
	for (int i = 2; i <= max; i++)
	{
		if (v[i] != 0)
		{

		}
		else
			for (int j = i * 2; j <= max; j += i)
				v[j] = 1;
	}
	for (int i = 0; i < w.size(); i++)
	{
		int count = 0;
		for (int k = w[i] + 1; k <= 2 * w[i]; k++)
			if (v[k] == 0)
				count++;
		cout << count << '\n';
	}
	return 0;
}