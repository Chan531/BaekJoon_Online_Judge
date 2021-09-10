#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, answer;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		answer = 0;
		cin >> s;
		vector<int> v(26);
		for (auto j : s)
			v[j - 'A']++;
		for (int j = 0; j < 26; j++)
			if (!v[j])
				answer += j + 'A';
		cout << answer << '\n';
	}
	return 0;
}