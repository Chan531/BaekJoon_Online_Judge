#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> ans;
string p = "Present!", s;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (p != "Present!" && s != "Present!")
			ans.push_back(p);

		p = s;
	}

	if (p != "Present!") ans.push_back(p);

	if (ans.empty()) cout << "No Absences";
	else for (auto i : ans) cout << i << '\n';
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