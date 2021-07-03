#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int n, num;
	cin >> n;
	deque<pair<int, int>> d;
	string s = "";
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		d.push_back(make_pair(num, i + 1));
	}
	while (1)
	{
		s += to_string(d.front().second);
		s += " ";
		int move = d.front().first;
		d.pop_front();
		if (d.empty()) break;
		if (move > 0)
		{
			move--;
			while (move != 0)
			{
				pair <int, int> p = make_pair(d.front().first, d.front().second);
				d.pop_front();
				d.push_back(p);
				move--;
			}
		}
		else
		{
			while (move != 0)
			{
				pair <int, int> p = make_pair(d.back().first, d.back().second);
				d.pop_back();
				d.push_front(p);
				move++;
			}
		}
	}
	cout << s;
}