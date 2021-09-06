#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	double n;
	string s;
	cin >> n >> s;
	if (count(s.begin(), s.end(), 'A') > n / 2)
		cout << 'A';
	else if (count(s.begin(), s.end(), 'A') < n / 2)
		cout << 'B';
	else
		cout << "Tie";
	return 0;
}