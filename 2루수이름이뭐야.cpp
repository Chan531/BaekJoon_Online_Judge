#include <iostream>

using namespace std;

int main(void)
{
	int n, a = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "anj")
			a = 1;
	}
	a ? cout << "构具;" : cout << "构具?";
	return 0;
}