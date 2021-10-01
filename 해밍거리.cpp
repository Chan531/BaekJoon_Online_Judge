#include <iostream>

using namespace std;

int main(void)
{
	int n, cnt;
	string s, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		cin >> s >> t;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] != t[j])
				cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
	}
	return  0;
}