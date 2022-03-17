#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string num, ans = "";
vector<string> arr;

bool cmp(string a, string b)
{
	return a + b > b + a;
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
}

void solution()
{
	sort(arr.begin(), arr.end(), cmp);
	for (auto i : arr)
		ans += i;
	ans[0] == '0' ? cout << 0 : cout << ans;
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
	cout.tie(NULL);

	solve();
	return 0;
}