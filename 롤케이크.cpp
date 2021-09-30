#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int l, n, a, b, gap = 0, gapn;
	cin >> l >> n;
	vector<int> v(l + 1), w(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		if (b - a > gap)
		{
			gap = b - a;
			gapn = i;
		}
		for (int j = a; j <= b; j++)
			if (!v[j])
			{
				v[j] = i;
				w[i]++;
			}
	}
	cout << gapn << '\n' << max_element(w.begin(), w.end()) - w.begin();
	return 0;
}