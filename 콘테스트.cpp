#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v, w;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		w.push_back(num);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	cout << v[9] + v[8] + v[7] << ' ' << w[9] + w[8] + w[7];
	return 0;
}