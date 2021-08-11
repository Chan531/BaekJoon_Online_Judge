#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int st = 0;
	string s;
	while (1)
	{
		getline(cin, s);
		if (s == "")
			st++;
		else
			st = 0;
		if (st == 2)
			break;
		cout << s << '\n';
	}
}

// 2번째 방법
/*#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int st = 0;
	string s;
	while (1)
	{
		getline(cin, s);
		if (cin.eof())
			break;
		cout << s << '\n';
	}
}*/