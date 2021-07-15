#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void)
{
	int n, age = 0;
	string name = "";
	vector<tuple <int, int, string>> info;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		info.push_back(make_tuple(age, i, name));
	}
	sort(info.begin(), info.end());
	for (int i = 0; i < info.size(); i++)
		cout << get<0>(info[i]) << ' ' << get<2>(info[i]) << '\n';
	return 0;
}