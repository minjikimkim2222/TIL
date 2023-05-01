여러 정렬 알고리즘을 오름차순으로 만드는 방법으로 살펴보자.

selection_sort
==============

## 1. 기본 로직
1. 정렬되지 않은 인덱스의 맨앞(초기 배열의 시작위치)부터, i값을 고정한다.
2. 현재 고정된 위치(i)값과 그 바로 다음 위치부터 size만큼 j값을 더해 두 값을 비교하는데, 
    i > j이면 swap해준다.
3. 다음 인덱스에서 위 과정을 반복해준다.

## 2. 시간 복잡도
배열이 어떻든 간에, 전체 배열에서 비교를 하므로, O(n^2) 
겁나 오래걸림..

## 3. 코드
<pre>
<code>
void selection_sort(int arr[], int size) //배열 시작주소, 배열 크기
{
  for (int i=0; i<size; i++)
  {
    for (int j=i+1; j<size; j++){
      if(arr[i] >= arr[j])
        swap(arr[i], arr[j]);
    }
  }
}
</code>
</pre>


insertion_sort(삽입 정렬)
======================

