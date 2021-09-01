#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num, rank;
	vector<int> v;
	for (int i = 0; i < 50; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> num;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < 50; i++)
	{
		if (num == v[i])
		{
			rank = i;
			break;
		}
	}
	if (rank < 5)
		cout << "A+";
	else if (rank < 15)
		cout << "A0";
	else if (rank < 30)
		cout << "B+";
	else if (rank < 35)
		cout << "B0";
	else if (rank < 45)
		cout << "C+";
	else if (rank < 48)
		cout << "C0";
	else
		cout << "F";
	return 0;

}