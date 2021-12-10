#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, csl, cnt = 1;
	string word, currentword;
	vector<string> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		arr.push_back(word);
	}
	sort(arr.begin(), arr.end());
	currentword = arr[0];
	csl = currentword.length();
	for (int i = 1; i < n; i++)
	{
		if (csl > arr[i].length() || currentword != arr[i].substr(0, csl))
			cnt++;
		currentword = arr[i];
		csl = currentword.length();
	}
	cout << cnt;
	return 0;
}