#include <iostream>

using namespace std;

int n;
string s, t;

void input()
{
	cin >> n >> s >> t;
}

void solution()
{
	if (n % 2)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == t[i])
			{
				cout << "Deletion failed";
				return;
			}
		}
			
		cout << "Deletion succeeded";
		return;
	}

	s == t ? cout << "Deletion succeeded" : cout << "Deletion failed";
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}