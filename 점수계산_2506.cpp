#include <iostream>

using namespace std;

int main(void)
{
	int n, num, pnum = 0, score = 0, con = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num && pnum)
			score += ++con;

		else if (num && !pnum)
		{
			score++;
			con++;
			pnum = 1;
		}
		else if (!num && pnum)
		{
			con = 0;
			pnum = 0;
		}
	}
	cout << score;
}