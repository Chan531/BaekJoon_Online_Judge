#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1, s2, t1 = "", t2 = "";
	int t;
	cin >> s1 >> s2;
	for (int i = 0; i < 8; i++)
	{
		t1 += s1[i];
		t1 += s2[i];
	}
	for (int i = 0; i < 14; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < t1.length() - 1; j++)
			{
				t = t1[j] + t1[j + 1] - 2 * '0';
				if (t < 10)
					t2 += to_string(t);
				else
					t2 += to_string(t - 10);
			}
			t1 = "";
		}
		else
		{
			for (int j = 0; j < t2.length() - 1; j++)
			{
				int t = t2[j] + t2[j + 1] - 2 * '0';
				if (t < 10)
					t1 += to_string(t);
				else
					t1 += to_string(t - 10);
			}
			t2 = "";
		}
	}
	cout << t1;
	return 0;
}