#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, time, total = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	total += v[0];
	time = v[0];
	for (int i = 1; i < n; i++)
	{
		v[i] += total;
		total = v[i];
		time += v[i];
	}
	cout << time;
	return 0;
}