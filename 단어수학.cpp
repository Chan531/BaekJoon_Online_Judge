#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, l, num = 0, ma;
	string s;
	cin >> n;
	vector<int> v(26);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		l = s.length();
		for (int j = 1; j <= l; j++)
			v[s[j - 1] - 'A'] += pow(10, l - j);
	}
	for (int i = 9; i >= 0; i--)
	{
		int ma = max_element(v.begin(), v.end()) - v.begin();
		num += i * v[ma];
		v[ma] = 0;
	}
	cout << num;
	return 0;
}