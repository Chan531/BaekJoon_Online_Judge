#include <iostream>

using namespace std;
int ms = -1, mc = 51, ml = 180;

bool check(int s, int c, int l)
{
	if (s > ms)
	{
		ms = s;
		mc = c;
		ml = l;
		return 1;
	}
	else if (s == ms)
	{
		if (c < mc)
		{
			ms = s;
			mc = c;
			ml = l;
			return 1;
		}
		else if (c == mc)
		{
			if (l < ml)
			{
				ms = s;
				mc = c;
				ml = l;
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	int n, s, c, l, ans;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> c >> l;
		if (check(s, c, l))
			ans = i;
	}
	cout << ans;
	return 0;
}