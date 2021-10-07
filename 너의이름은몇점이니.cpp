#include <iostream>

using namespace std;

int main(void)
{
	int n, answer = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		answer += s[i] - 'A';
	cout << answer + n;
	return 0;
}