1.정의와 성질
=========
### 1. 정의
- LIFO, **한쪽 끝(top)에서만** 원소를 넣거나 빼는 구조, 프링글스 통/엘레베이터 </br>

### 2. 성질
1. 원소의 추가와 제거가 O(1)
2. 제일 상단의 원소 확인이 O(1)
3. 제일 상단이 아닌 나머지 원소들의 확인/변경이 **원칙적으로** 불가능
- 물론 배열을 직접 구현하면 제일 상단이 아닌 나머지 원소들을 확인, 변경할 수 있겠지만,
    - 기본적인 스택 제공 연산은 3가지로, 원소의 추가/제거/제일 상단의 원소 확인, 총 3가지임.

참고] 구현 => algorithm 레포에 있음(간단, 배열로)


2.stack STL
=====
- 멤버함수 : push(3), pop(), top(), size(), empty()
- stack이 empty일 때 top함수 쓰면, run time error!
      - 스택이 비었는데 맨 꼭대기 원소 출력하라고 했더니, 이상한 쓰레기값이 출력됨.
<pre>
    <code>
#include <stack> // #include << stack >>
#include <iostream> // #include << iostream >> 

using namespace std;

int main(void)
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30); // 10 20 30

    cout << s.size() << '\n'; // 3

    if (s.empty()) cout << "s is empty\n";
    else cout << "s is not empty\n"; // s is not empty

    s.pop();
    cout << s.top() << '\n'; // 20

    s.pop();
    cout << s.top() << '\n'; // 10

    s.pop();
    cout << s.top() << '\n'; // runtime error
    // stack이 비었는데, 맨 위 원소 출력하라니까 쓰레기값, 이상한 값이 출력됨
}
    </code>
</pre>

