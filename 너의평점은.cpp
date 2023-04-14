#include <iostream>

using namespace std;

string name, grade;
double score, total, ans;

double result()
{
	if (grade == "A+")
		return 4.5;

	else if (grade == "A0")
		return 4.0;

	else if (grade == "B+")
		return 3.5;

	else if (grade == "B0")
		return 3.0;

	else if (grade == "C+")
		return 2.5;

	else if (grade == "C0")
		return 2.0;

	else if (grade == "D+")
		return 1.5;

	else if (grade == "D0")
		return 1.0;

	else
		return 0;
}

void solve()
{
	for (int i = 0; i < 20; i++)
	{
		cin >> name >> score >> grade;

		if (grade == "P")
			continue;

		total += score;
		ans += score * result();
	}

	cout << fixed;
	cout.precision(6);

	cout << ans / total;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}