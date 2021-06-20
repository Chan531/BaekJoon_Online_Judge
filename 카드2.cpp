#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	while (q.size() != 1)
	{
		q.pop();
		int i = q.front();
		q.pop();
		q.push(i);
	}
	cout << q.front();
	return 0;
}