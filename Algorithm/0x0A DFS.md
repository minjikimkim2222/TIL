**다차원 배열**에서 인접한 곳 위주로 **탐색**이 필요한 문제는 전부 BFS로 푼다고 보면 된다.</br>
단, 나중에 그래프나 트리에서는 DFS를 쓰기에 DFS 개념 정도를 알아둘 필요가 있다!
</br>


0.알고리즘 정의
===
다차원 배열의 각 칸을 방문할 때 **깊이를 우선해** 방문하는 알고리즘은 **DFS**,
깊이 대신 **너비** 위주 방문은 **BFS**

1.코드 예제
===
### 1. 예제를 보며 느낀 점 : </br>
  **BFS**는 한 지점의 인접한 상하좌우를 전부 거리순으로 차곡차곡 방문 후, 그 다음 지점으로 이동해 해당 
지점 또한 인접한 상하좌우 방문. 즉, 큐를 이용해 FIFO으로 먼저 들어온 애부터 나가게 함. </br>
  단, **DFS**는 스택의 LIFO을 이용해, 한 지점의 모든 깊이를 다 탐색한 뒤, 더 이상 갈 곳이 없다면 다음 지점으로 이동해
 해당 다음 지점도 막히지 않을 때까지 모든 깊이를 탐색하는 느낌. </br>
### 2. 코드
- 큐에서 스택으로만 바뀜
<pre>
 <code>
#include <iostream> // iostream
#include <stack> // stack, DFS
#include <utility> // utility

using namespace std;

int board[502][502] = 
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 방문 가능 지역, 0이 방문 불가능 지역

bool visit[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n = 7, m = 10; // n : 행, m : 열
 int main(void)
 {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> S;

    S.push({0,0}); // 시작지점 넣기
    visit[0][0] = 1; // 시작지점 방문 표시

    while (!S.empty()){
        auto cur = S.top();
        S.pop();

        cout << '(' << cur.first << ", " << cur.second << ") -> ";
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 바깥
            if (visit[nx][ny] == 1 || board[nx][ny] == 0) continue; // 이미 방문했거나 방문 불가능 지역은 지나치기
            visit[nx][ny] = 1;
            S.push({nx,ny});
        }
    }
 }
 </code>
</pre>

2.DFS VS BFS, 실제 응용?
===
![image](https://github.com/minjikimkim2222/study/assets/96869808/4c0935c6-2b14-4cc3-9006-0d2f3778c484)

1. 구현 : DFS는 스택을, BFS는 큐를
2. **방문순서[사진 참고]** :
 - **BFS**
   1. 냇가에 던진 돌로 인해 동심원이 생기는 것처럼 상하좌우로 퍼져나간다.
   2. BFS의 성질인 (시작지점으로부터) 거리 순으로 방문한다.
 - DFS </br>
   1. 뭔가 한 방향으로 막힐 때까지 쭉 직진
   2. BFS의 성질인 "현재 보는 칸으로부터 추가되는 **인접한 칸 거리**가 **현재 보는 칸보다 1만큼** 더 떨어져있다" 성립 안 함

3. **실제 응용**
   거리 측정은 BFS만 할 수 있으니, 다차원 배열 순회 문제는 계속 BFS </br>
   DFS는 그래프나 트리 자료구조 배울 때 등장
   DFS는 다차원 배열에서 스택을 써서 깊이를 우선으로 탐색하는 알고리즘 정도.