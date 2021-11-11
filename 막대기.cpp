#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n, num, cnt = 1, max;
	stack<int> st;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		st.push(num);
	}
	max = st.top();
	st.pop();
	while (!st.empty())
	{
		if (st.top() > max)
		{
			max = st.top();
			cnt++;
		}
		st.pop();
	}
	cout << cnt;
	return 0;
}