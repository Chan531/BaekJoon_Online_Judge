#include <iostream>

using namespace std;

int main(void)
{
	string name;
	int age, weight;
	while (1)
	{
		cin >> name >> age >> weight;
		if (age > 17 || weight >= 80)
			cout << name << " Senior\n";
		else if (name == "#")
			break;
		else
			cout << name << " Junior\n";
	}
	return 0;
}