#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	stack<int> s;
	for (int i = 0; i < a; i++)
	{
		while (!s.empty())
			s.pop();
		string ss = "";
		cin >> ss;
		for (int j = 0; j < ss.size(); j++)
		{
			if (ss[j] == '(')
				s.push(1);
			else
			{
				if (s.size() == 0)
				{
					cout << "NO" << endl;
					break;
				}
				else
					s.pop();
			}
			if (j == ss.size() - 1 && s.size() != 0)
				cout << "NO" << endl;
			else if (j == ss.size() - 1 && s.size() == 0)
				cout << "YES" << endl;
		}
	}
}