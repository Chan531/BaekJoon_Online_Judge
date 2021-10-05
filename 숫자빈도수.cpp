#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	string s;
	cin >> n >> m;
	vector<int> v(10);
	for (int i = 1; i <= n; i++)
	{
		s = to_string(i);
		for (int j = 0; j < s.length(); j++)
			v[s[j] - '0']++;
	}
	cout << v[m];
	return 0;
}