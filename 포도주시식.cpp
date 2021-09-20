#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	cin >> n;
	vector<int> v(n + 1), w(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	w[1] = v[1];
	w[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++)
		w[i] = max({ v[i] + v[i - 1] + w[i - 3], w[i - 1], w[i - 2] + v[i]});
	cout << *max_element(w.begin(), w.end());
	return 0;
}