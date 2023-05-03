1.c++ STL -> list
===============
이부분 0x04 정리 후 같이 정리!

2.c++ 범위기반 for문 루프
==========
## 1. 간단한 문법 형식

<pre>
<code>
for (element_declaraion : array)
  statement;
</code>
</pre>

- 여기서 루프는 각 array의 모든 요소를 방문해, element_declartion에 선언된 
변수에 현재 배열 요소의 값을 할당한다.
- 단, element_declaration이 배열 요소와 같은 자료형이어야 함.

## 2. 예제
### 1. 배열
<pre>
<code>
#include <iostream>
using namespace std;
int main(void)
{
  int arr[] = {0, 1, 2, 3, 4, 5}
  for (int number : arr)
    cout << number << ' ';
  return (0);
}
</code>
</pre>
- for문 루프에서, arr의 첫 번째 요소인 0이 number에 할당되고 0을 출력한뒤, 그 다음은 number의 1이 출력,
... 그렇게 5까지 출력된다.
- 이처럼 범위 지정 루프문은 for문에 있는 배열의 모든 원소가 남아있지 않을 때까지 작업 반복.

### 2. 리스트
<pre>
<code>
list< char > li; 
for (char temp : li)
{
  std::cout << temp;
}
</code>
</pre>
- 물론 얘도 가능. 그러나, 대부분은 3번 auto를 추천. 가장 간편하기에!

### 3. auto
<pre>
<code>
for (auto number : arr명/리스트명)
  cout << number;
</code>
</pre>
