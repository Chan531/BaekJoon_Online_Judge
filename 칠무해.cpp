#include <iostream>
#include <map>

using namespace std;

int n, cnt = 0;
double grade;
map<double, int> score;
map<double, int>::iterator it;

void input()
{
	cout << fixed;
	cout.precision(3);
	cin >> n;
	while (n--)
	{
		cin >> grade;
		score[grade]++;
	}
}

void solution()
{
	for (it = score.begin(); it != score.end(); it++)
	{
		if (cnt == 7)
			break;

		while (cnt != 7 && it->second)
		{
			cout << it->first << '\n';
			it->second--;
			cnt++;
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}