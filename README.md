## 문제 풀다가 발견한 유용한 것들 모음 (2021.09.06 최종 수정)

**1. 시간초과 발생시**

```C++
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
```




**2. 프로그램 강제 종료**
```c++
exit(0);
```

**3. 문자 관련 함수**

* tolower : 대문자 -> 소문자 변경

* toupper : 소문자 -> 대문자 변경

-> 다른 건 그대로 반환

* isupper(문자열) -> 대문자 판별 (맞으면 1 반환)

* islower(문자열) -> 소문자 판별

(#include cctype -> 여기부터는 이거 해야된다는데 이거 안 해도 돌아가던디 뭐지?)

* isdigit() -> 숫자 판별

* isspace() -> 공백 판별

* isalpha() -> 알파벳 판별


* **3-2. 문자열 전체를 바꾸려면**
```C++
#include <algorithm>
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

**4. 벡터를 바꾸려면**
```C++
#include <algorithm>
replace(v.begin(), v.end(), 바꾸려는 값, 바꿀 값);
```

**5. map : key값과 value값을 연결!**

-> 매우 유용하게 쓸 수 있을 듯

-> vector처럼 많이 쓰인다니까 자주 써보삼

map에 요소 존재 여부 확인
```C++
map<int, int>:: iterator it;
it = m.find(5);
```
만약 m[5]가 존재하지 않는다면 it == m.end()를 가리키게 됨!!!! (백준 9184번 참고)

**6. 문자열 공백 기준으로 자르기**
```C++
#include <sstream>
string str="java c c++ python";
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
        while (getline(ss, stringBuffer, ' '))
    {
        x.push_back(stringBuffer);
        cout<<stringBuffer<<" ";
    }
```

**7. 문자열 일부분 자르기**
```C++
string s = "HelloWorld!"
s.substr(0, 5) == "Hello"; (시작점, 자를 길이)
```

**8. Pair 클래스**

두 객체를 하나의 객체로 만들어줌!

**9. Tuple**

3개 이상의 객체를 하나의 객체로 만들어줌!
```C++
tuple<int, int, string, string> info;
info = make_tuple(1, 2, "hi", "hello");
get<0>(info) -> 1
get<3>(info) -> "hello"
```

**10. 최댓값, 최솟값 알 수 있는 함수 + 인덱스**
```C++
#include <algorithm>
*max_element(a.begin(), a.end());
*min_element(a.begin(), a.end());
index = max_element(v.begin(), v.end()) - v.begin();
```

**11. 소수점 자릿수 고정**
```C++
cout << fixed;
cout.precision(원하는 자릿수);
```

**12. 중복 원소 정렬 후 제거**
```C++
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```
unique를 적용해주면 시작점이 중복된 원소가 몰아져있는 끝 값으로 적용됨

**13. 탐색에서 제일 중요한 거**

방문 여부 확인 + index 조절

**14. 제곱, 제곱근 함수**
```C++
pow(10, 2); -> 100
sqrt(9); -> 3
```

**15. 올림, 내림, 반올림 함수**
```C++
ceil(4.2); -> 5
floor(4.2); -> 4
```
* 반올림 방법
```C++
floor(4.2 + 0.5); -> 4
floor(4.7 + 0.5); -> 5
-> round(3.2); ==> 3 / round라는 함수가 존재!
```

**16. 벡터의 총합**
```C++
#include <numeric>
accumulate(v.begin(), v.end(), 0);
```
0 -> 합의 초기
(만약 합이 int를 초기화하면 0을 0LL 같은 long long 형으로 적어줘야 함)
* **16-1. 벡터의 곱 (1-> 곱의 초기)**
```C++
accumulate(v.begin(), v.end(), 1, multiplies<int>());
```

**17. DP - 동적계획법 - 다이나믹프로그래밍**

1 - Top - Down 방식, 기존 방법
```C++
fibo(n) = fibo(n-1) + fibo(n-2);
```
2- Bottom - UP 방식, 아래부터 계산 
```C++
for (int i = 2; i <= n; i++)
    fibo(i) = fibo(i - 1) + fibo(i - 2);
```

**18. 벡터 내 원소 개수 확인 함수**
```C++
count(v.begin(), v.end(), num);
```
* **18-1. 조건에 만족하는 원소 개수**
```C++
count_if(v.begin(), v.end(), 조건);
```

**19. 문자를 문자열로 변경**

to_string 같은 걸로 하면 int 값이 들어감

고로 그냥 string s = ""선언해주고 추가해주자^^

**20. 합집합, 교집합 함수** (하기 전에 정렬해야된다는데 왜인지는 모르겠....ㅠㅠ)
```C++
set_union(v.begin(), v.end(), w.begin(), w.end(), back_inserter(x));
set_intersection(v.begin(), v.end(), w.begin(), w.end(), back_inserter(x));
```
v, w -> 비교 대상, x -> 합집합이 될 대상

* **20-1. 삽입 함수 예제**
```C++
v1 : 1, 3, 5 , v2 : 10, 30, 50
back_inserter -> 대상의 맨 끝에서부터 삽입함
v2 : 10, 30, 50, 1, 3, 5
front_inserter -> 대상의 맨 앞에서부터 삽입함
v2 : 5, 3, 1, 10, 30, 50
```

**21. 이진탐색 유용한 함수**

반드시 정렬된 벡터에 사용해야함!
```C++
upper_bound(v.begin(), v.end(), num)
-> num을 초과하는 숫자의 위치를 반환
lower_bound(v.begin(), v.end(), num)
-> num과 같거나 큰 숫자의 위치를 반환
index를 알고 싶으면 - v.begin()
```

**22. 조합**
```C++
next_permutation(v.begin(), v.end());
-> 1 2 3라면 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1하고 각각 true 반환, 만약 다음이 없다면 false를 반환
```
* **22-1. nCr 하는 법**
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> s{ 1, 2, 3, 4 };
    vector<int> temp{ 1, 1, 0, 0 };
 
    do {
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1)
                cout << s[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(temp.begin(), temp.end()));
}
출처: https://mjmjmj98.tistory.com/38 [dlroW ,olleH]
```

**23. 유클리드 알고리즘(재귀)**
```C++
int gcd(int a, int b) {

    if (b == 0) 
        return a;

    else 
        return gcd(b, a % b);
}
-> 재귀 방식은 수가 커지면 메모리초과 발생 가능
```

**24. 공백 포함 문자열 입력 받기**
```C++
getline(cin, s);
-> cin >> n; 뒤에 getline 사용할 시 입력 버퍼 상의 '\n'문자까지 읽어서 문제가 생긴다.
그러므로 cin을 사용한 다음 cin.ignore() 함수를 호출해야한다.
```

**25. 문자열 비교**
```C++
int strcmp(str1, str2);
-> 같으면 0, 다르면 사전순에 따라 앞서면 -1, 뒤에 있으면 1 반환
int strncmp(str1, str2, n);
-> n까지 같으면 0 다르면 1 반환
```

**26. 2차원 벡터 선언**
```C++
vector<vector<int>> v(10, vector<int>(10,0));
-> 총 100칸의 0으로 채워진 2차원 벡터 생성
```

**27. erase관련**
```C++
iter = l.erase(iter);
```
EX) l.erase(iter);는 iter가 가리키는 부분을 삭제하고 다음 값을 반환한다. 
이 때, 위와 같은 방식으로 반환하는 iter 값을 받지 않으면 에러가 발생한다.

**28. 피사노 주기**

- 피보나치 수를 어떤 수 K로 나눌 때, 나머지는 항상 주기를 가지게 됨

- 주기의 길이 P라고 하면 N번 째 피보나치 수를 M으로 나눈 나머지는 N%P번 째 피보나치 수를 M으로 나눈 나머지와 같다.

M=10^k (k>2)일 때, 주기는 항상 15*10^(K-1)이다.

**29. 아무 것도 입력되지 않을 때**
```C++
cin.eof() == true;
```
-> cin.eof()는 true를 반환한다.

**30. pair 정렬 관련**
```C++
struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};
```
-> first를 기준으로 오름차순, second를 기준으로 내림차순 (부등호가 왼쪽이면 오름차순, 오른쪽이면 내림차순으로 이해하는 게 편할 거 같다....)
