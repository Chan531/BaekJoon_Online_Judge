#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[1010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution(int idx)
{
	vector<int> o, e;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2)	o.push_back(arr[i]);
		else e.push_back(arr[i]);
	}

	sort(o.begin(), o.end());
	sort(e.begin(), e.end(), greater<>());

	int oi = 0, ei = 0;

	cout << "Case #" << idx << ": ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2) cout << o[oi++] << ' ';
		else cout << e[ei++] << ' ';
	}
	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution(i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}