#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n, a, b, c, cnt, ma, aa = 0, bb = 0, cc = 0;
	cin >> n;
	vector<vector<int>> v(4, vector<int>(4));
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		v[1][a]++;
		v[2][b]++;
		v[3][c]++;
	}
	for (int i = 1; i <= 3; i++)
	{
		aa += v[1][i] * i;
		bb += v[2][i] * i;
		cc += v[3][i] * i;
	}
	vector<int> w = { 0, aa, bb, cc };
	ma = *max_element(w.begin(), w.end());
	cnt = count(w.begin(), w.end(), ma);
	if (cnt == 1)
		cout << max_element(w.begin(), w.end()) - w.begin() << ' ' << ma;
	else
	{
		int m1 = 0, m2 = 0;
		for (int i = 1; i <= 3; i++)
		{
			if (!m1 && w[i] == ma)
				m1 = i;
			else if (w[i] == ma)
				m2 = i;
		}
		if (v[m1][3] > v[m2][3])
			cout << m1 << ' ' << ma;
		else if (v[m1][3] < v[m2][3])
			cout << m2 << ' ' << ma;
		else
		{
			if (v[m1][2] > v[m2][2])
				cout << m1 << ' ' << ma;
			else if (v[m1][2] < v[m2][2])
				cout << m2 << ' ' << ma;
			else
				cout << 0 << ' ' << ma;
		}
	}
	return 0;
}