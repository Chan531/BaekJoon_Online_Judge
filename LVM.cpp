#include <iostream>
#include <vector>

using namespace std;

int n, r;
string s[1010];
int m[1010];
vector<int> v;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];

		if (s[i] == "PUSH" || s[i] == "IFZERO")
			cin >> m[i];
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == "PUSH")
			v.push_back(m[i]);

		else if (s[i] == "STORE")
		{
			r = v.back();
			v.pop_back();
		}

		else if (s[i] == "LOAD")
			v.push_back(r);

		else if (s[i] == "PLUS")
		{
			v[v.size() - 2] += v.back();
			v.pop_back();
		}

		else if (s[i] == "TIMES")
		{
			v[v.size() - 2] *= v.back();
			v.pop_back();
		}

		else if (s[i] == "IFZERO")
		{
			int b = v.back();
			v.pop_back();

			if (b == 0)
				i = m[i] - 1;
		}

		else
		{
			cout << v.back();
			break;
		}
	}
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