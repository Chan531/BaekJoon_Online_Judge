#include <iostream>

using namespace std;

int main(void)
{
	cout << fixed;
	cout.precision(1);
	int t, n, c, credit;
	double g, grade;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		credit = 0;
		grade = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> c >> g;
			credit += c;
			grade += c * g;
		}
		cout << credit << ' ' << grade / credit << '\n';
	}
	return 0;
}