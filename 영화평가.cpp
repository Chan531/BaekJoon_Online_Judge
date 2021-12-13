#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, l, h;
	double num, sum = 0;
	vector<double> score;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		score.push_back(num);
	}
	sort(score.begin(), score.end());
	for (int i = l; i < n - h; i++)
		sum += score[i]; 
	cout << fixed;
	cout.precision(10);
	cout << sum / (n - l - h);
	return 0;
}