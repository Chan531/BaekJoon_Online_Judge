#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, k, j = 1;
	queue<int> q;
	cin >> n >> k;
	cout << '<';
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (q.size() != 1)
	{
		if (j == k)
		{
			cout << q.front() << ", ";
			j = 0;
		}

		else
			q.push(q.front());

		q.pop();
		j++;
	}
	cout << q.front() << '>';
	return 0;
}