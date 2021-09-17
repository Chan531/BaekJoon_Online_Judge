#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t, n, count;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v(n + 1);                          // 0 -> 개방 상태
		count = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				if (!v[j])
					v[j] = 1;
				else
					v[j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
			if (!v[i])
				count++;
		cout << count << '\n';
	}
	return 0;
}