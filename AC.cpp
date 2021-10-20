#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, st;
	string s, t, l;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		st = 1;
		cin >> s >> m >> t;
		deque<int> dq;
		for (int j = 0; j < t.length(); j++)
		{
			l = "";
			while (isdigit(t[j]))
				l += t[j++];
			if (l != "")
				dq.push_back(stoi(l));
		}
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'R')
				st *= -1;
			if (s[j] == 'D')
			{
				if (st == 1)
				{
					if (!dq.empty())
						dq.pop_front();
					else
					{
						cout << "error\n";
						break;
					}
				}
				if (st == -1)
				{
					if (!dq.empty())
						dq.pop_back();
					else
					{
						cout << "error\n";
						break;
					}
				}
			}
			if (j == s.length() - 1)
			{
				cout << '[';
				if (st == 1)
				{
					while (!dq.empty())
					{
						cout << dq.front();
						dq.pop_front();
						if (!dq.empty())
							cout << ',';
					}
				}
				if (st == -1)
				{
					while(!dq.empty())
					{
						cout << dq.back();
						dq.pop_back();
						if (!dq.empty())
							cout << ',';
					}
				}
				cout << "]\n";
			}
		}
	}
}