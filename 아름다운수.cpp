#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, cnt;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> v(10);
		cnt = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (!v[s[j] - '0'])
			{
				v[s[j] - '0']++;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}