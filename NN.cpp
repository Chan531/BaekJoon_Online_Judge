#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, m, count = 0, index = 0, l;
	cin >> n >> m;
	string s = to_string(n);
	l = s.length();
	if (l * n <= m)
	{
		for (int i = 0; i < n; i++)
			cout << s;
		return 0;
	}
	while (count != m)
	{
		cout << s[index++];
		if (index == l)
			index = 0;
		count++;
	}
	return 0;
}