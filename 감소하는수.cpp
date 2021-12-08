#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, index = 0;
	cin >> n;
	queue<long long> q;
	vector<long long> arr = { 0,1,2,3,4,5,6,7,8,9 };
	for (long long i = 0; i < 10; i++)
		q.push(i);
	while (!q.empty() && n >= arr.size())
	{
		long long num = q.front();
		q.pop();

		for (long long i = 0; i < num % 10; i++)
		{
			arr.push_back(num * 10 + i);
			q.push(num * 10 + i);
		}
	}
	if (arr.size() > n)
		cout << arr[n];
	else
		cout << -1;
	return 0;
}