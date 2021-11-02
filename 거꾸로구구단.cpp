#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, m;
	vector<int> v;
	string s;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		m = n * i;
		s = to_string(m);
		reverse(s.begin(), s.end());
		v.push_back(stoi(s));
	}
	cout << *max_element(v.begin(), v.end());
}