#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<int> digit(11);
int an, b, ans = -1;
string a;

void noc(string s, int cnt)
{
	if (cnt == a.length())
	{
		an = stoi(s);
		if (an < b && ans < an)
			ans = an;
		return;
	}
	for (int j = 0; j < a.length(); j++)
	{
		if (!digit[j])
		{
			digit[j] = 1;
			s += a[j];
			noc(s, cnt + 1);
			s.pop_back();
			digit[j] = 0;
		}
	}
}

int main(void)
{
	cin >> a >> b;
	sort(a.begin(), a.end());
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '0')
			continue;
		digit[i] = 1;
		string st = "";
		st += a[i];
		noc(st, 1);
		digit[i] = 0;
	}
	cout << ans;
	return 0;
}