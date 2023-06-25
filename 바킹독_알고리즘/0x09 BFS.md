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
-> 모든 칸이 큐에 1번씩 들어가므로, 시간복잡도는 칸이 N개일 때 : O(N) </br></br>

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

2.기본 BFS 구조 + 자주 하는 실수
====

## 2-1. 자주 하는 실수
1. 시작점에 방문했다는 표시를 안 한다.
     -> 그러면 쓸데없이 두 번이나 방문할 수 있다.
2. **큐에 넣을 때 방문했다**는 표시를 하는 대신, 큐에서 빼낼 때 방문했다는 표시를 한다.
3. 이웃한 원소가 범위를 벗어났는지에 대한 체크를 잘못한 경우.

### 2-2. 기본 BFS 구조
<pre>
  <code>
#include <iostream> // iostream
#include <queue> // queue
#include <utility> // utility

using namespace std;

#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1 : 파란칸 (방문가능한 곳), 0 : 빨간칸(방문 안할 곳)

 bool visit[502][502]; // 해당 칸의 방문 여부를 저장

 int n = 7, m = 10; // 각각 행과 열

 int dx[4] = {1,0,-1,0};
 int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향

 int main(void)
 {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q; // 좌표를 위한 좌표
    
    visit[0][0] = 1; // 시작지점 (0,0)을 방문했다!
    Q.push({0,0});

    while (!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++){ // 상하좌우
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 유효한 범위가 아님(범위 밖인 경우 넘어감)
            if (visit[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나, 파란 칸이 아닌 경우
            visit[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
 }
  </code>
</pre>
