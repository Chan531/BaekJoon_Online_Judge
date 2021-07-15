#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int n, num = 0;
	double sum = 0;
	int fre = 1;
	int count = 1;
	vector<int> v;
	vector<int> w;
	map<int, int> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
		sum += num;
		m[num]++;
		if (m[num] > fre)
		{
			fre = m[num];
			count = 1;
			if (w.size() != 0)
				w.clear();
			w.push_back(num);
		}
		else if (m[num] == fre)
		{
			count++;
			w.push_back(num);
		}
	}
	sort(v.begin(), v.end());
	double ave = sum / n;
	if (ave > 0)
		ave = floor(ave + 0.5);
	else
	{
		ave = ceil(ave - 0.5);
	}
	cout << int(ave) << '\n';
	cout << v[v.size() / 2] << '\n';
	if (n == 1)
		cout << v[0] << '\n';
	else if (count > 1)
	{
		sort(w.begin(), w.end());
		cout << w[1] << '\n';
	}
	else
	{
		cout << w[0] << '\n';
	}
	if (n == 1)
		cout << 0;
	else if (v[0] * v[v.size() - 1] < 0)
		cout << abs(v[0]) + v[v.size() - 1];
	else 
		cout << v[v.size() - 1] - v[0];
	return 0;
}