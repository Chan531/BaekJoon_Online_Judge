#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> v(10001);

int main(void)
{
	int n, num;
	vector<int> s;
	vector<int> p;
	v[1]++;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 2; j <= num; j++)
			if (v[j] == 0)
			{
				s.push_back(j);
				for (int k = j * 2; k <= num; k += j)
					v[k] = 1;
			}
		int t = 0;
		while (t != s.size())
		{
			if (v[num - s[t]] == 0)
				p.push_back(abs(num - 2 * s[t]));
			t++;
		}
		int k = *min_element(p.begin(), p.end());
		cout << (num - k) / 2 << ' ' << (num - k) / 2 + k << '\n';
		p.clear();
		s.clear();
	}
	return 0;
}