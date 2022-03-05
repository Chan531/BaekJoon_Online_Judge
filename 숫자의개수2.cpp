#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> cnt(10);
long long a, b, c;
string n;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	a *= b;
	a *= c;
	n = to_string(a);
	for (int i = 0; i < n.length(); i++)
		cnt[n[i] - '0']++;
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << '\n';
	
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