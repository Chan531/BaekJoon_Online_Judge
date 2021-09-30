#include <iostream>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 1; i <= 3; i++)
	{
		if (!(i % 2))
			cout << ":fan::" << s << "::fan:\n";
		else
			cout << ":fan::fan::fan:\n";
	}
	return 0;
}