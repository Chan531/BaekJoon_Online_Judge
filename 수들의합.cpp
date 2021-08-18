#include <iostream>

using namespace std;

int main() {
	long long int s, sum = 0;
	cin >> s;
	int n = 1, num = 0;
	while (sum <= s)
	{
		sum += n;
		n++;
		num++;
	}
	cout << num - 1;
	return 0;
}