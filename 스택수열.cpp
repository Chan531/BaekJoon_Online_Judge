#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	vector<int> v;
	vector<char> c;
	stack<int> s;
	int n = 0;
	int num = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		v.push_back(n);
	}

	for (int i = 0; i < a; i++)
	{
		if (num < v[i])
		{
			c.push_back('+');
			s.push(num + 1);
			num++;
			i--;
		}
		else if (num == v[i])
		{
			c.push_back('-');
			s.pop();
		}
		else
		{
			if (s.top() == v[i])
			{
				c.push_back('-');
				s.pop();
			}
			else
			{
				cout << "NO" << endl;
				i = a - 1;
			}
		}
	}
	if (s.size() == 0)
	{
		for (auto i : c)
		{
			cout << i << "\n";

		}
	}
}