#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(1);
vector<int> add(100001);
int a, save = 0;

int sum(int n)
{
	if (n == a + 1)
		return save;
	add[n] = add[n - 1];
	if (v[n] > 0)
	{
		add[n] += v[n];
		if (save <= add[n])
			save = add[n];
	}
	else
	{
		if (add[n] + v[n] >= 0)
		{
			add[n] += v[n];
		}
		else
		{
			add[n] = 0;
		}
	}
	return sum(n + 1);
}

int main(void)
{
	int num;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	int answer = sum(1);
	if (answer == 0)
	{
		v.erase(v.begin());
		cout << *max_element(v.begin(), v.end());
	}
	else
		cout << answer;
	return 0;
}	