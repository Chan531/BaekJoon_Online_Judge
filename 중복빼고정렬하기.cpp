#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;
	vector<int> v;
	vector<int>::iterator it, it2;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	it2 = unique(v.begin(), v.end());
	for (it = v.begin(); it != it2; it++)
		cout << *it << ' ';
	return 0;
}