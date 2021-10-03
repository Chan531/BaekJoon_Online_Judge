#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << '\n';
	}
	return 0;
}