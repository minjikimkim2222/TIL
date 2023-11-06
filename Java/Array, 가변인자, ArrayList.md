# Array, 가변인자, ArrayList
## 1) Array

### 1-1. array
#### 만드는 법
``` java
int[] marks = new int[4]; // 배열의 선언
int[] marks = {1, 3, 4, 5}; // 배열의 선언과 초기화를 동시에
```
#### 객체의 배열 생성
``` java
class Person {
}

Person[] persons = new Person[5]; // person ==> Person[5] { null, null, null, null, null }
Person[] person2 = {new Person(), new Person()}; // person2 ==> Person[2] { Person@6f496d9f, Person@723279cf }
```
#### array를 출력하는 2가지 방법
1. 배열의 길이 활용
     ``` java
     int[] marks = {10, 30, 20, 40};
     
     for (int i = 0; i < marks.length; i++) // array 배열의 길이는 메소드가 아니고 속성
       System.out.println(marks[i]);
     ```
3. for (type var : array)
     ``` java
     int[] marks = {10, 30, 20, 40};
     for (int mark : marks)
       System.out.println(mark);
     ```
</br>

### 1-2. Arrays
#### array vs Arrays
- array : 일련의 데이터 구조를 순차적으로 저장하는 **데이터구조**. 배열은 고정된 크기를 가지며, 한번 크기가 설정되면 변경 불가능.
- Arrays : Java 표준 라이브러리에 포함된 **클래스**. 배열과 관련된 유용한 **메서드** 제공.
#### Arrays 정적 메소드
1. toString()
  - 파라미터로 지정된 **배열**의 내용을 문자열(String)타입으로 반환하는 메서드
  - 코드
    ``` java
    int[] marks = {1,2,3,4,5};
    // marks ==> int[5] { 1, 2, 3, 4, 5 }

    Arrays.toString(marks);
    // $29 ==> "[1, 2, 3, 4, 5]"

    marks
    // marks ==> int[5] { 1, 2, 3, 4, 5 }
    ```
3. Compare(), Sort(), Fill()
   <details>
     <summary>Compare && equals 메서드</summary>

      - Arrays.compare() 메서드 : </br>
          - input : 배열 2개, output : int형
          - 두 배열의 요소를 차례로 비교하면서, 처음으로 다른 요소를 만나면, 두 요소의 차이를 반환. 
          - 즉, 두 배열의 모든 요소가 같으면 0 반환, 첫 번째 배열이 두 번째 배열보다 작으면 음수를, 크면 양수를 반환. </br>
      - Arrays.equals() 메서드
          - input : 배열 2개, output : boolean
          - 두 배열의 길이와 요소가 동일하면 true, 그렇지 않으면 false
      - 코드 예제
        ``` java
        int[] arr1 = {1,2,3};
        int[] arr2 = {1,2,4};

        Arrays.compare(arr1, arr2); // -1 반환
        Arrays.equals(arr1, arr2); // false 반환
        ```
   </details>

   <details>
     <summary>fill 메서드</summary>

      - Arrays.fill() 메서드 : </br>
          - input : 배열 참조와 채울 값, output : void형
          - 배열의 모든 요소를 지정된 값을 채운다.
      - 코드 예시
        ``` java
        int[] arr = new int[5];
        // arr ==> int[5] {0, 0, 0, 0, 0};

        Arrays.fill(arr, 100);

        arr
        // arr ==> int[5] {100, 100, 100, 100, 100}
        ```
   </details>
   <details>
     <summary>sort 메서드</summary>

      - Arrays.sort() 메서드 : </br>
          - input : 정렬할 배열, output : void형
          - 배열의 요소를 오름차순으로 정렬한다. 이 메서드는 다양한 타입의 배열을 정렬하기 위해 overload 되어있다.
      - 코드 예시
        ``` java
        int[] arr = {10 , 2, 4, 90, 2};
        // arr ==> int[5] { 10, 2, 4, 90, 2 }
        Arrays.sort(arr);
        arr
        // int[5] { 2, 2, 4, 10, 90 }

        String[] arr2 = {"abd", "abc", "gdc", "bds"};
        // arr2 ==> String[4] { "abd", "abc", "gdc", "bds" }
        Arrays.sort(arr2);
        arr2
        // arr2 ==> String[4] { "abc", "abd", "bds", "gdc" }

        
        ```
   </details>
</br>

## 2) 가변인자
### 가변인자 등장이유, 개념
- 고정인자가 아닌 **가변인자**이다. 즉, 1개의 인자도 넣고 싶고, 2개의 인자, 3개의 인자, .. 등등을 넣고 싶다.
- 단, java에서 가변인자는 하나의 메서드에 대해 **하나**의 타입만 허용.
### 만드는 법
- 메서드의 **파라미터에서만** 사용 가능.
- 가변인자는 **array**로 처리가 된다.
- 가변인자는 **맨 마지막 자리**에, **딱 한 개**만 가능.
``` java
void print(char c, int... values) {
     System.out.println("char : " + c + ", values : " + Arrays.toString(values));
} // values 매개변수가 가변인자 int... 타입이므로, "values는 정수 배열" 로 처리가 된다.

print('a', 1);
// char : a, values : [1]

print('b', 1, 2, 3);
// char : b, values : [1, 2, 3]

print('b', 1, 2, 3, 56);
// char : b, values : [1, 2, 3, 56]
```

## 3) ArrayList
