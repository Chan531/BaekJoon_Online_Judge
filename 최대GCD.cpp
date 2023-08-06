#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s, t;
int ans, idx;
vector<int> arr;

void input()
{
	getline(cin, s);
}

int gcd(int a, int b)
{
	if (!b)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	ans = 0;
	idx = 0;

	while (idx <= s.length())
	{
		if (s[idx] == ' ' || idx == s.length())
		{
			arr.push_back(stoi(t));
			t = "";
			idx++;
			continue;
		}

		t += s[idx++];
	}

	for (int i = 0; i < arr.size(); i++)
		for (int j = i + 1; j < arr.size(); j++)
			ans = max(ans, gcd(arr[i], arr[j]));

	cout << ans << '\n';
	arr.clear();
}

void solve()
{
	int tc;
	cin >> tc;
	cin.ignore();

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}