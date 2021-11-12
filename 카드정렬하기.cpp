#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, cnt = 0, a, b;
	priority_queue <int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pq.push(num);
	}
	while (pq.size() != 1)
	{
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		cnt += a + b;	
		pq.push(a + b);
	}
	cout << cnt;
	return 0;
}