#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v = { 100,100,200,200,300,300,400,400,500 };
	vector<int> score;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		score.push_back(n);
	}
	if (accumulate(score.begin(), score.end(), 0) < 100)
	{
		cout << "none";
		return 0;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (score[i] > v[i])
			{
				cout << "hacker";
				return 0;
			}
		}
	}
	cout << "draw";
	return 0;
}