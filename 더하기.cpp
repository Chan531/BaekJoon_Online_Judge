#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n = 0;
	string s, num = "";
	cin >> s;
	for (auto i : s)
	{
		if (i != ',')
			num += i;
		else
		{
			n += stoi(num);
			num = "";
		}
	}
	cout << n + stoi(num);
	return 0;
}