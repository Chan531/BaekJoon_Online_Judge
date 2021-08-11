#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 1; i <= n; i++)
	{
		d.push_back(i);
	}
	while (1)
	{
		cout << d.front() << ' ';
		d.pop_front();
		if (d.empty())
			break;
		d.push_back(d.front());
		d.pop_front();
	}
	return 0;
}