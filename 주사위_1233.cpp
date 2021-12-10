#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int s1, s2, s3, maxcnt;
	vector<int> sum(81);
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			for (int k = 1; k <= s3; k++)
				sum[i + j + k]++;
		}
	}
	maxcnt = *max_element(sum.begin(), sum.end());
	for (int i = 1; i <= 81; i++)
	{
		if (sum[i] == maxcnt)
		{
			cout << i;
			break;
		}
	}
	return 0;
}