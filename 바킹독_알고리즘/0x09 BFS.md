바킹독 알고리즘 강의 링크 : https://blog.encrypted.gg/941

0.알고리즘 설명 BFS(Breadth First Search)
=========
- 다차원 배열에서 각 칸을 방문할 때, **너비를 우선으로** 방문하는 알고리즘
- 해당 칸의 **상하좌우**를 전부 방문하고, 다음 칸으로! </br>

1.예시 [절차]
====
1. 시작하는 칸을 큐에 넣고, **방문했다**는 표시를 남김
2. 큐에서 원소를 꺼내, 그 칸에 **상하좌우**로 인접한 칸에 대해 3번 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 </br>
해당 칸을 큐에 삽입
4. 큐가 빌 때까지 2번 반복
-> 모든 칸이 큐에 1번씩 들어가므로, 시간복잡도는 칸이 N개일 때 : O(N)

### 참고, pair STL ###
<pre>
  <code>
    /*
    값의 쌍을 저장할 수 있는 pair
    주로 좌표를 생성할 때, 이 pair을 씀
    -> 해당 목차에서는 BFS 탐색할 때, 큐에 좌표를 넣어야 하는데 이때 pair를 씀
    */

#include <iostream>
#include <utility> // pair 정의 헤더 < utility >

using namespace std;

int main(void){
    pair<int,int> t1 = make_pair(10,13);
    pair<int,int> t2 = {4,6};

    cout << t1.first << '\n';
    cout << t2.second << '\n';

    // 쌍 중에 첫번째 원소를 first로 접근, 두 번째 원소를 second로 접근

    if (t2 < t1) cout << "t2 < t1\n";  // t2 < t1
    // pair은 알아서 앞쪽부터 대소관계 비교한 뒤, 뒤 까지 검사함
    
}
  </code>
</pre>
