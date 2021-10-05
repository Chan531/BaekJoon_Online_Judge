#include <iostream>

using namespace std;

string printscore(int score)
{
	if (score >= 97)
		return "A+";
	else if (score >= 90)
		return "A";
	else if (score >= 87)
		return "B+";
	else if (score >= 80)
		return "B";
	else if (score >= 77)
		return "C+";
	else if (score >= 70)
		return "C";
	else if (score >= 67)
		return "D+";
	else if (score >= 60)
		return "D";
	else
		return "F";
}

int main(void)
{
	int n, score;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> score;
		cout << name << ' ' << printscore(score) << '\n';
	}
	return 0;
}