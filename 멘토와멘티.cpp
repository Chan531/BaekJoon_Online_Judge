#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, idx = 1;
unordered_map<string, int> nm;
unordered_map<int, string> mn;
vector<string> name, mentee[100010];

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		string a, b;
		cin >> a >> b;

		if (!nm[a])
		{
			name.push_back(a);
			nm[a] = idx++;
			mn[nm[a]] = a;
		}

		mentee[nm[a]].push_back(b);
	}

	sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); i++)
	{
		sort(mentee[nm[name[i]]].begin(), mentee[nm[name[i]]].end(), greater<>());

		for (auto j : mentee[nm[name[i]]])
			cout << mn[nm[name[i]]] << ' ' << j << '\n';
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