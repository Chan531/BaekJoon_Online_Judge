#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, ord, count = 0;
	string s, s1, s2;
	vector<string> v;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		v.push_back(s2);
		if (s1 == s)
		{
			ord = i;
		}
	}
	for (int i = 0; i < ord; i++)
	{
		if (v[i] == v[ord])
			count++;
	}
	cout << count;
	return 0;
}