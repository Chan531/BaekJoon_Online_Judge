#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string s = "";
	vector<vector<string>> v(20000);
	vector<string> answer;
	int n, count = 0;
	int num = 0;
	int max = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v[s.length()].push_back(s);
		if (s.length() > max)
			max = s.length();
	}
	while (num != max)
	{
		num++;
		if (v[num].size() == 0)
		{

		}
		else if (v[num].size() == 1)
		{
			answer.push_back(v[num][0]);
			count++;
		}
		else
		{
			sort(v[num].begin(), v[num].end());
			v[num].erase(unique(v[num].begin(), v[num].end()), v[num].end());
			for (auto l : v[num])
			{
				answer.push_back(l);
				count++;
			}
		}
	}
	for (auto i : answer)
	{
		cout << i << '\n';
	}
	return 0;
}