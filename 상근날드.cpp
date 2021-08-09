#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	vector<int> v, w;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> n;
		w.push_back(n);
	}
	cout << *min_element(v.begin(), v.end()) + *min_element(w.begin(), w.end()) - 50;
	return 0;
}