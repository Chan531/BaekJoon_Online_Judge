#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, m;
	vector<int> v(201);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[num + 100]++;
	}
	cin >> m;
	cout << v[m + 100];
	return 0;
}