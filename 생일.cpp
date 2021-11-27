#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, day, month, year;
	string name;
	vector<tuple<int, int, int, string>> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> day >> month >> year;
		arr.push_back(make_tuple(year, month, day, name));
	}
	sort(arr.begin(), arr.end());
	cout << get<3>(arr[n - 1]) << '\n' << get<3>(arr[0]);
	return 0;
}