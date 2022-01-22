#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	while (n--)
	{
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}