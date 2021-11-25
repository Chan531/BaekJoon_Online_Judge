#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<string, int>> arr;

string eng(char c)
{
	switch (c)
	{
		case '0':
			return "zero";
		case '1':
			return "one";
		case '2':
			return "two";
		case '3':
			return "three";
		case '4':
			return "four";
		case '5':
			return "five";
		case '6':
			return "six";
		case '7':
			return "seven";
		case '8':
			return "eight";
		case '9':
			return "nine";
	}
}

void makearr(int n)
{
	string engnum = "", num = to_string(n);
	for (int j = 0; j < num.length(); j++)
		engnum += eng(num[j]);
	arr.push_back(make_pair(engnum, n));
	return;
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
		makearr(i);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].second << ' ';
		if ((i + 1) % 10 == 0)
			cout << '\n';
	}
	return 0;
}