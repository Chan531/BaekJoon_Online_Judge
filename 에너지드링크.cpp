#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
double l;
vector<double> drink;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		drink.push_back(l);
	}
}

void solution()
{
	sort(drink.begin(), drink.end());
	for (int i = 0; i < n - 1; i++)
		drink[n - 1] += drink[i] / 2;
	cout << drink[n - 1];
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

	cout << fixed;
	cout.precision(6);

	solve();
	return 0;
}