#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string checkpal(string s)
{
	int left = 0;
	unsigned int right = s.length() - 1;
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return "No\n";
		}
		left++;
		right--;
	}
	return "Yes\n";
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << checkpal(s);
	}
	return 0;
}