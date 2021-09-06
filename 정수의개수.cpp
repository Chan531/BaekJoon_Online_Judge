#include <iostream>

using namespace std;

int main(void)
{
	int count = 1;
	string s;
	cin >> s;
	for (auto i : s)
	{
		if (i == ',')
			count++;
	}
	cout << count;
	return 0;
}