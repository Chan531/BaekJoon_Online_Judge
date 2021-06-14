#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a = 0;
	int n = 0;
	cin >> a;
	string s = "";
	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		if (s == "top")
		{
			if (v.size() != 0)
				cout << v[v.size() - 1] << endl;
			else
				cout << -1 << endl;
		}
		else if (s == "size")
			cout << v.size() << endl;
		else if (s == "empty")
		{
			if (v.size() != 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else if (s == "pop")
		{
			if (v.size() != 0)
			{
				cout << v[v.size() - 1] << endl;
				v.pop_back();
			}
			else
				cout << -1 << endl;
		}
		else if (s == "push")
		{
			cin >> n;
			v.push_back(n);
		}
	}
}