#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string s;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		if (s.length() < 3)
			continue;
		if (s.find("FBI") < s.length())
			v.push_back(i + 1);
	}
	if (v.size())
		for (auto i : v)
			cout << i << ' ';
	else
		cout << "HE GOT AWAY!";
	return 0;
}