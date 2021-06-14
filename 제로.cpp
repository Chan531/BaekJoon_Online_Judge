#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int a = 0;
	int n = 0;
	int answer = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	while (!s.empty())
	{
		answer += s.top();
		s.pop();
	}
	cout << answer;
}