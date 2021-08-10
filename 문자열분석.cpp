#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int s, b, n, e;
	while (1)
	{
		s = 0; b = 0; n = 0; e = 0;
		getline(cin, str);
		if (str == "")
			break;
		for (auto i : str)
		{
			if (isdigit(i))
				n++;
			else if (isupper(i))
				b++;
			else if (islower(i))
				s++;
			else
				e++;
		}
		cout << s << ' ' << b << ' ' << n << ' ' << e << '\n';
	}
}