#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
vector<int> v;

void pushsix(int x)
{
	int sixnum = 1;
	string s = to_string(x);
	if (s.length() > 1)
	{
		if (s[s.length() - 2] == '6')
			sixnum++;
		if (sixnum == 2 && s.length() > 2 && s[s.length() - 3] == '6')
			sixnum++;
	}
	for (int j = 0; j < pow(10, sixnum); j++)
	{
		if (sixnum == 1)
			v.push_back(x * 1000 + 66 * 10 + j);
		else if (sixnum == 2)
			v.push_back(x * 1000 + 6 * 100 + j);
		else
			v.push_back(x * 1000 + j);
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 6)
			pushsix(i);
		else
			v.push_back(i * 1000 + 666);
	}
	cout << v[n - 1];
	return 0;
}