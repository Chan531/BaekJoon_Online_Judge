#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, s = 0;
	vector<int> v, w;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		w.push_back(num);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		s += v[i] * w[i];
	}	
	cout << s;
	return 0;
}