#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v, w(2);
	for (int i = 0; i < 7; i++)
		w.push_back(1);
	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	while (next_permutation(w.begin(), w.end()))
	{
		vector<int> answer;
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i] == 1)
				answer.push_back(v[i]);
		}
		if (accumulate(answer.begin(), answer.end(), 0) == 100)
		{
			sort(answer.begin(), answer.end());
			for (auto i : answer)
				cout << i << '\n';
			break;
		}
	}
	return 0;
}