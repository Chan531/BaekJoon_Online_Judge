#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k, n;
	char c;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k;
		priority_queue<int> ma;
		priority_queue<int, vector<int>, greater<int>> mi;
		map<int, int> bi, sm;
		for (int j = 0; j < k; j++)
		{
			cin >> c >> n;
			if (c == 'I')
			{
				ma.push(n);
				mi.push(n);
			}
			else
			{
				if (n == 1 && !ma.empty())
				{
					sm[ma.top()]++;
					ma.pop();
				}
				else if (n == -1 && !mi.empty())
				{
					bi[mi.top()]++;
					mi.pop();
				}
			}
			while (!mi.empty() && sm[mi.top()])
			{
				sm[mi.top()]--;
				mi.pop();
			}
			while (!ma.empty() && bi[ma.top()])
			{
				bi[ma.top()]--;
				ma.pop();
			}
		}
		if (ma.empty() && mi.empty())
			cout << "EMPTY\n";
		else
			cout << ma.top() << ' ' << mi.top() << '\n';
	}
	return 0;
}