#include <iostream>
#include <numeric>

using namespace std;

int main(void)
{
	string s1, s2;
	long long answer = 0, ss2;
	cin >> s1 >> s2;
	ss2 = accumulate(s2.begin(), s2.end(), 0) - '0' * int(s2.length());
	for (int i = 0; i < s1.length(); i++)
			answer += (s1[i] - '0') * ss2;

	cout << answer;
	return 0;
}