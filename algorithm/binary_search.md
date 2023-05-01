
이진 탐색(binary search), 백준 0x03 3273 풀 때 참고
======================

## 1. 뜻
오름차순으로 이미 "정렬된" 정수 배열에서, 원하는 정수를 찾을 때 쓴다.
코드를 볼 때, low, high, mid를 기준으로 생각하면 된다.

## 2. 코드
<pre>
<code>
int binary_search(int arr[], int n, int key){
  int low, high;
  int mid;
  
  low = 0;
  high = n -1;
  while (low <= high) {
    mid = (low + high) / 2;
    
    if (key == data[mid]) // 탐색 성공
      return mid;
    else if (key < data[mid]) //이미 정렬이 되어있으니까 가능
      high = mid - 1;
    else if (key > data[mid])
      low = mid + 1;
    }
  }
  return (-1);
}
</code>
</pre>

## 3. 시간 복잡도 => O(logn)
이진 탐색에서는 각 단계에서 배열의 크기가 반으로 줄어들기에, 상대적인 비율의 의미로 배열의 크기가 1이 되는 순간이
최악의 경우이다.
전체 데이터 개수를 n이라고 하자.
1) 첫 번째 탐색 후, 절반만 남아있는 수 -> n/2개
2) 두 번째 탐색 후, 다시 절반이 남은 수 -> n/2 * 1/2개
3) 세 번째 탐색 후, 다시 절반이 남은 수 -> n/2 * 1/2 * 1/2개
.
.
.
k) k번째 탐색후, 남아있는 데이터 수 -> (1/2)^k * n
따라서 최악의 경우 (1/2)^k * n = 1. k = log2n -> 따라서 시간복잡도 O(logn)
