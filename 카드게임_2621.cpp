#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	char c, pc;
	int n, count = 1, four = 0, three = 0, two1 = 0, two2 = 0;                                            // count -> 연속 여부 확인
	vector<int> v(10), co(26), w, num;
	for (int i = 0; i < 5; i++)
	{
		cin >> c >> n;
		co[c - 'A']++;
		v[n]++;
		num.push_back(n);
	}
	for (int i = 1; i < 10; i++)
	{
		if (!w.empty() && w.back() == 1 && w.back() == v[i])
			count++;
		if (v[i] == 4)
			four = i;
		else if (v[i] == 3)
			three = i;
		else if (v[i] == 2)
		{
			if (two1 == 0)
				two1 = i;
			else
				two2 = i;
		}
		w.push_back(v[i]);
	}
	if (count == 5 && *max_element(co.begin(), co.end()) == 5)
		cout << 900 + *max_element(num.begin(), num.end());

	else if (four != 0)
		cout << 800 + four;

	else if (three != 0 && two1 != 0)
		cout << 700 + three * 10 + two1;

	else if (*max_element(co.begin(), co.end()) == 5)
		cout << 600 + *max_element(num.begin(), num.end());

	else if (count == 5)
		cout << 500 + *max_element(num.begin(), num.end());

	else if (three != 0)
		cout << 400 + three;

	else if (two1 != 0 && two2 != 0)
		cout << 300 + 10 * two2 + two1;

	else if (two1 != 0)
		cout << 200 + two1;

	else
		cout << 100 + *max_element(num.begin(), num.end());
	return 0;
}