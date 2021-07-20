#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v(10001);

void self(int n)
{
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++)
	{
		n += s[i] - '0';
	}
	if (n > 10000)
	{
		return;
	}
	v[n]++;
	if (v[n] == 1)
		self(n);
}

int main(void)
{
	for (int i = 1; i < 10001; i++)
	{
		if (v[i] == 0)
			self(i);
	}
	for (int i = 1; i < 10001; i++)
	{
		if (v[i] == 0)
			cout << i << "\n";
	}
	return 0;
}