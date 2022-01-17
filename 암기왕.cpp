#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarysearch(int start, int end, int num, vector<int>& arr)
{
	if (start > end)
		return 0;

	int mid = (start + end) / 2;

	if (arr[mid] > num)
		return binarysearch(start, mid - 1, num, arr);

	else if (arr[mid] == num)
		return 1;

	else
		return binarysearch(mid + 1, end, num, arr);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, num;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			cout << binarysearch(0, n - 1, num, arr) << '\n';
		}
	}
	return 0;
}

/* <algorithm> 해더 파일안에 있는 binary_search 함수를 이용

출처: https://blockdmask.tistory.com/167 [개발자 지망생]

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, num;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			cout << binary_search(arr.begin(), arr.end(), num) << '\n';
		}
	}
	return 0;
}
*/