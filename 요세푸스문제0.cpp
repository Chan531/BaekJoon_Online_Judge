#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	int k = 0;
	cin >> n >> k;
	queue<int> q;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	while (q.size() != 0)
	{
		for (int i = 1; i < k; i++)
		{
			int a = q.front();
			q.pop();
			q.push(a);
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << '<';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}