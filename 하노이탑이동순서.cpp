#include <iostream>
#include <cmath>

using namespace std;

int n;

void hanoi(int from, int by, int to, int num)
{
	if (num == 1)                                // �� �� ���Ǹ� ���Ҵٴ� ���� �ǹ��ϹǷ� ��������� �������� �Űܳ���
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(from, to, by, num - 1);                // n - 1���� ������ ��������� �������� �Űܾ� �ϹǷ� -> �׷��� �� �� ������ ��������� �������� �ű�� �� ������
	cout << from << ' ' << to << '\n';           // n - 1���� ������ ��� �������� �Ű� �������Ƿ� ������ ������ �������� ���ƾ� ��
	hanoi(by, from, to, num - 1);                // �������� �Ű� ���� n - 1���� ������ �������� �Űܾ� �� -> �� �� ������� �������� �̿�
}

void solve()
{
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';          // �ϳ���ž ���� Ƚ�� 
	hanoi(1, 2, 3, n);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}