#include <iostream>
#include <cmath>

using namespace std;

double checkgrade(string s)
{
	if (s == "A+")
		return 4.3;
	else if (s == "A0")
		return 4.0;
	else if (s == "A-")
		return 3.7;
	else if (s == "B+")
		return 3.3;
	else if (s == "B0")
		return 3.0;
	else if (s == "B-")
		return 2.7;
	else if (s == "C+")
		return 2.3;
	else if (s == "C0")
		return 2.0;
	else if (s == "C-")
		return 1.7;
	else if (s == "D+")
		return 1.3;
	else if (s == "D0")
		return 1.0;
	else if (s == "D-")
		return 0.7;
	else
		return 0.0;
}

int main(void)
{
	cout << fixed;
	cout.precision(2);
	int n, g, sum = 0;
	double total = 0;
	string s, gr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> g >> gr;
		total += checkgrade(gr) * g;
		sum += g;
	}
	cout << round(total / sum * 100) / 100;
	return 0;
}