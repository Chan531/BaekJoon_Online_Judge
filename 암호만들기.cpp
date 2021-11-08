#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, vow, cons;
	char c;
	cin >> m >> n;
	vector<char> v(n);
	vector<int> w(n);
	for (int i = 0; i < m; i++)
		w[i] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		v[i] = c;
	}
	sort(v.begin(), v.end());
	do
	{
		string s = "";
		vow = 0;
		cons = 0;
		for (int i = 0; i < n; i++)
		{
			if (w[i])
				s += v[i];
		}
		for (int i = 0; i < m; i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				vow++;
			else
				cons++;
		}
		if (vow >= 1 && cons >= 2)
			cout << s << '\n';
	} while (prev_permutation(w.begin(), w.end()));
	return 0;
}