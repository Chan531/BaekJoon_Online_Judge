#include <iostream>

using namespace std;

int main(void)
{
	int n = 0, m = 0, num;
	for (int i = 0; i < 4; i++)
	{
		cin >> num; 
		n += num;
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		m += num;
	}
	n > m ? cout << n : cout << m;
	return 0;
}