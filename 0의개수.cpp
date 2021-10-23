#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, l, count;
	string s;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		count = 0;
		cin >> n >> m;
		for (int i = n; i <= m; i++)
		{
			s = to_string(i);
			l = s.length();
			for (int j = 0; j < l; j++)
				if (s[j] == '0')
					count++;
		}
		cout << count << '\n';
	}
	return 0;
}