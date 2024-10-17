#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> v[11];

void input()
{
	cin >> n;
}

void solution()
{
	v[1] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'L', 'M' };
	v[2] = { 'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M' };
	v[3] = { 'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M' };
	v[4] = { 'A', 'B', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[5] = { 'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[6] = { 'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[7] = { 'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[8] = { 'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[9] = { 'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M' };
	v[10] = { 'A', 'B', 'C', 'F', 'G', 'H', 'L', 'M' };

	cout << v[n].size() << '\n';
	for (auto i : v[n]) cout << i << ' ';
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