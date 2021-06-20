#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int a = 0;
	vector<int> v(10000);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a);
		v[a]++;
	}
	int k = 0;
	int i = 1;
	while (k < n)
	{
		while (v[i] != 0)
		{
			printf("%d\n", i);
			v[i]--;
			k++;
		}
		i++;
	}
	return 0;
}