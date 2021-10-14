#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> big;
	priority_queue<int> small;
	int n, num, st = 10001;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (st >= num)
		{
			small.push(num);
			if (small.size() > big.size() + 1)
			{
				big.push(small.top());
				small.pop();
			}
		}
		else if (st < num)
		{
			if (big.empty() || small.size() > big.size())
				big.push(num);
			else if (big.top() < num)
			{
				small.push(big.top());
				big.pop();
				big.push(num);
			}
			else
			{
				small.push(num);
			}
		}
		st = small.top();
		cout << st <<'\n';
	}
	return 0;
}