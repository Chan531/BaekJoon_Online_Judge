#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<long long> one(n + 1);
	vector<long long> zero(n + 1);
	one[1] = 1;
	zero[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		one[i] = zero[i - 1];
		zero[i] = one[i - 1] + zero[i - 1];
	}
	cout << one[n] + zero[n];
	return 0;
}