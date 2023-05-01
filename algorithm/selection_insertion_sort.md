여러 정렬 알고리즘을 오름차순으로 만드는 방법으로 살펴보자.

1.selection sort
==================

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


2.insertion_sort(삽입 정렬) -> 이거 쓸 바엔 복잡도 똑같은 1번 쓴다..
======================

## 1. 기본 로직
1. 두 번째 배열원소부터 비교를 시작한다. 이때 비교대상은 항상 현재 위치보다 앞에 있는 배열 원소들이다.
    - 예를 들어, arr[1](고정)은 arr[0]과 비교를 하고,
    - arr[2](고정)는 arr[1]과 arr[0], arr[3](고정)은 arr[2], arr[1], arr[1]과 비교를 한다.
2. 이렇게 마지막 배열원소까지 쭉 비교를 하다, arr[i](고정)이 비교대상(i보다 앞에 있는 원소)보다 작다면, 
swap!


## 2. 시간 복잡도
앞선 삽입정렬과 똑같이 모든 배열 원소의 비교를 하므로, O(n^2)의 시간복잡도이다.

## 3. 코드
<pre>
<code>
void insertion_sort(int arr[], int size)
{
    for(int i=1; i<size; i++){
        int key = arr[i], j = i - 1;
        while (j >= 0 && key < arr[j]){
            swap(arr[j], arr[j+1]);
            j--;
         }
       arr[j+1] = key;
    }
}
