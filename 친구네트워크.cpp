#include <iostream>
#include <unordered_map>

using namespace std;

int f;              // 친구 관계의 수
unordered_map<string, string> root;
unordered_map<string, int> cnt;
// root -> 부모 노드, height -> 자신이 부모 노드인 트리의 높이

string find(string n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	cin >> f;

	while (f--)
	{
		string a, b;
		cin >> a >> b;

		if (root.find(a) == root.end())
		{
			root[a] = a;
			cnt[a] = 1;
		}

		if (root.find(b) == root.end())
		{
			root[b] = b;
			cnt[b] = 1;
		}

		string aroot = find(a);
		string broot = find(b);

		if (aroot == broot)
		{
			cout << cnt[aroot] << '\n';
			continue;
		}

		root[broot] = aroot;
		cnt[aroot] += cnt[broot];

		cout << cnt[aroot] << '\n';
	}
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		solution();
		root.clear();
		cnt.clear();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}