
# Reference type과 String 클래스, Wrapper 클래스
## 1) Reference Type
### 뜻
- Primitive type을 제외한 모든 type
- 내가 만든 class, java에 predefined class (String, BigDecimal ..)
### 메모리
- 자바 프로그램이 실행될 때, 메모리는 크게 두 종류. **stack**과 **heap** </br>
  **Primitive type**은 stack에 저장되지만, reference type은 다르다.
- "**실제**" 객체 정보는 Heap에 저장되고 </br>
  **객체가 저장된 경로**(메모리주소; 참조)는 해당 객체변수의 "값"에 저장됨.
- 예시
```java
int i = 5;
Class Animal {
  int id;
  public Animal(id) {
    this.id = id;
  }
}
Animal dog = new Animal(12);
Animal cat = new Animal(15);

```
<details>
  <summary>예시코드 메모리 모습</summary>
  
  
![image](https://github.com/minjikimkim2222/study/assets/96869808/b975a59b-8731-49a4-8dfd-18729c39dcde)
  - Java의 reference type(참조 변수)는 객체의 메모리 위치를 저장하는데 사용되며, 이를 통해 객체의 속성 및 메서드에 엑세스할 수 있다.
</details>

### assignment
- Reference type의 assignment는 실제 값이 아니라, 객체의 메모리주소를 할당한다.
<details>
  <summary>reference type의 할당</summary>

  ![image](https://github.com/minjikimkim2222/study/assets/96869808/7130b3b4-867c-4569-b519-d5ddf7c7fd07)
  - nothing => null, nothing변수의 값에 원래 객체의 메모리주소가 있어야 하지만, 비어있다는 의미.
  - 그런데, cat"값" == AnimalCat의 메모리주소값이, nothing에 할당됨
  - 즉, nothing과 cat은 모두 똑같은 위치의 객체(Animal Cat)을 가리키고 있다.
</details>

### 비교연산자(==)
## 2) String 클래스

## 3) Wrapper 클래스

## 4) 기타
### 이클립스, 자바 API 탐색
