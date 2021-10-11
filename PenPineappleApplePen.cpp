#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, count = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s.substr(i, 4) == "pPAp")
		{
			count++;
			i += 3;
		}
	}
	cout << count;
	return 0;
}