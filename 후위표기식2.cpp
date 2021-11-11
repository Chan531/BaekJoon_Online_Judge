#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void cal(stack<double>& st, char c)
{
	double a = st.top();
	st.pop();
	double b = st.top();
	st.pop();
	if (c == '+')
		st.push(a + b);

	else if (c == '-')
		st.push(b - a);

	else if (c == '*')
		st.push(a * b);

	else
		st.push(b / a);
}

int main(void)
{
	int n;
	double num;
	stack<double> st;
	vector<int> v(26);
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			if (!(v[s[i] - 'A']))
			{
				cin >> num;
				v[s[i] - 'A'] = num;
			}
			st.push(v[s[i] - 'A']);
		}
		else
			cal(st, s[i]);
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}