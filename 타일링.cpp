#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string sadd(string a, string b)
{
	long long sum = 0;
	string result = "";
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		result += (sum % 10) + '0';
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	int n;
	vector<string> v(251);
	v[0] = "1";
	v[1] = "1";
	v[2] = "3";
	for (int i = 3; i <= 250; i++)
	{
		v[i] = sadd(v[i - 2], sadd(v[i - 1], v[i - 2]));
	}
	while (1)
	{
		cin >> n;
		if (cin.eof())
			break;
		cout << v[n] << '\n';
	}
	return 0;
}