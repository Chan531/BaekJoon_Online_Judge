#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n, a, b;
	stack<int> wash, dry, clean;
	cin >> n;
	for (int i = n; i >= 1; i--)
		wash.push(i);
	while (clean.size() != n)
	{
		cin >> a >> b;
		if (a == 1)
		{
			while (b--)
			{
				dry.push(wash.top());
				wash.pop();
			}
		}
		else
		{
			while (b--)
			{
				clean.push(dry.top());
				dry.pop();
			}
		}
	}
	while (!clean.empty())
	{
		cout << clean.top() << '\n';
		clean.pop();
	}
	return 0;
}