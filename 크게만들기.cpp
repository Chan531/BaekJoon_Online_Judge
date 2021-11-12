#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	int n, k;
	string l;
	stack<int> s, t;
	cin >> n >> k >> l;
	for (int i = l.length() - 1; i >= 0; i--)
		t.push(l[i] - '0');
	while (k && !t.empty())
	{
		while (k && !s.empty() && s.top() < t.top())
		{
			s.pop();
			k--;
		}
		s.push(t.top());
		t.pop();
	}
	if (t.empty())
	{
		while (k)
		{
			s.pop();
			k--;
		}
	}
	while (!s.empty())
	{
		t.push(s.top());
		s.pop();
	}
	while (!t.empty())
	{
		cout << t.top();
		t.pop();
	}
	return 0;
}