#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, m;
	cin >> n;
	vector<int> v, w(n + 1), answer;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
		answer.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				w[i] = max(w[i], w[j] + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		m = 0;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && w[i] > w[j])
				m = max(m, answer[j]);
		}
		answer[i] += m;
	}
	cout << *max_element(answer.begin(), answer.end());
	return 0;
}