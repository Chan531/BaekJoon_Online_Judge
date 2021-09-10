#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string s;
	while (1) 
	{
		n = 0;
		getline(cin, s);
		if (s == "#")
			break;
		for (auto i : s)
		{
			i = tolower(i);
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
				n++;
		}
		cout << n << '\n';
	}
	return 0;
}