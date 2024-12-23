#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<string> v[12];

void input()
{
	cin >> n >> k;
}

void init()
{
	v[1].push_back("1");
	v[2].push_back("1+1");
	v[2].push_back("2");
	v[3].push_back("1+1+1");
	v[3].push_back("2+1");
	v[3].push_back("1+2");
	v[3].push_back("3");
}

string convert(int n)
{
	if (n == 1) return "+1";
	else if (n == 2) return "+2";
	else return "+3";
}

void solution()
{
	init();

	for (int i = 4; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			for (auto k : v[i - j]) 
				v[i].push_back(k + convert(j));

	if (v[n].size() < k) cout << -1;
	else
	{
		sort(v[n].begin(), v[n].end());
		cout << v[n][k - 1];
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