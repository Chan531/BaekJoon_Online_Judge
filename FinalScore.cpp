#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
	int a, b, g, score = 0;
	string name;
	map<string, int> goal;
	vector<string> teama, teamb;
	cin >> a >> b >> g;
	while (a--)
	{
		cin >> name;
		teama.push_back(name);
	}
	while (b--)
	{
		cin >> name;
		teamb.push_back(name);
	}
	for (int i = 0; i < g; i++)
	{
		cin >> name;
		goal[name]++;
	}
	for (auto i : teama)
		score += goal[i];
	if (score > g - score)
		cout << 'A';
	else if (score >= g - score)
		cout << "TIE";
	else
		cout << 'B';
	return 0;
}