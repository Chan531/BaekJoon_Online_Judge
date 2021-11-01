#include <iostream>

using namespace std;

string s;
int aka = 1;

void check()
{
	if (!aka)
	{
		cout << "IPSELENTI";
		exit(0);
	}
}

void akaraka(int start, int end)
{
	check();

	if (start == end)
		return;

	int st = start;
	int en = end;
	int mid = (start + end) / 2;
	while (st < en)
	{
		if (s[st++] != s[en--])
		{
			aka = 0;
			return;
		}
	}
	if ((end - start) % 2)
	{
		akaraka(start, mid);
		akaraka(mid + 1, end);
	}
	else
	{
		akaraka(start, mid - 1);
		akaraka(mid + 1, end);
	}
}

int main(void)
{
	cin >> s;
	int start = 0, end = s.length() - 1;
	akaraka(start, end);
	aka ? cout << "AKARAKA" : cout << "IPSELENTI";
	return 0;
}