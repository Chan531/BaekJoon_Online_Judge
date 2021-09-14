#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makepi(string p)
{
	int psize = p.length();
	vector<int> pi(psize);
	int j = 0;
	for (int i = 1; i < psize; i++)
	{
		while (j > 0 && p[j] != p[i])
			j = pi[j - 1];
		if (p[j] == p[i])
			pi[i] = ++j;
	}
	return pi;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int j = 0;
	string t, p;
	getline(cin, t);
	getline(cin, p);
	int plength = p.length();
	int tlength = t.length();
	vector<int> pi = makepi(p), v;
	for (int i = 0; i < tlength; i++)
	{
		while (j > 0 && t[i] != p[j])
			j = pi[j - 1];
		if (t[i] == p[j])
		{
			if (j == plength - 1)
			{
				v.push_back(i - plength + 2);
				j = pi[j];
			}
			else
				j++;
		}
	}
	cout << v.size() << '\n';
	for (auto i : v)
		cout << i << ' ';
	return 0;
}