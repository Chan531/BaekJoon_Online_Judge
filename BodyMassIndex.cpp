#include <iostream>

using namespace std;

double w, h, bmi;

void input()
{
	cin >> w >> h;
}

void solution()
{
	bmi = w / (h * h);

	if (bmi > 25)
		cout << "Overweight";

	else if (bmi >= 18.5)
		cout << "Normal weight";

	else
		cout << "Underweight";
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