#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, budget, sum = 0;
	cin >> n;
	vector<int> claim(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		claim[i] = num;
	}
	cin >> budget;
	sort(claim.begin(), claim.end());
	for (int i = 0; i < n; i++)
	{
		if ((budget - sum) / (n - i) < claim[i])
		{
			cout << (budget - sum) / (n - i);
			return 0;
		}
		sum += claim[i];
	}
	cout << claim[n - 1];
	return 0;
}