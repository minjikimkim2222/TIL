
# Reference type과 String 클래스, Wrapper 클래스
## 1) Reference Type
### 뜻
- Primitive type을 제외한 모든 type
- 내가 만든 class, java에 predefined class (String, BigDecimal ..)
### 메모리
- 자바 프로그램이 실행될 때, 메모리는 크게 두 종류. **stack**과 **heap**
  **Primitive type**은 stack에 저장되지만, reference type은 다르다.
- "**실제**" 객체 데이터는 Heap에 저장되고 </br>
  **객체가 메모리 주소**, 즉 참조는 해당 객체변수의 "값"에 저장됨.
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
- Primitive type의 assignment는 실제 값이 저장되는 반면...
<details>
  <summary>reference type의 할당</summary>

  ![image](https://github.com/minjikimkim2222/study/assets/96869808/7130b3b4-867c-4569-b519-d5ddf7c7fd07)
  - nothing => null, nothing변수의 값에 원래 객체의 메모리주소가 있어야 하지만, 비어있다는 의미.
  - 그런데, cat"값" == AnimalCat의 메모리주소값이, nothing에 할당됨
  - 즉, nothing과 cat은 모두 똑같은 위치의 객체(Animal Cat)을 가리키고 있다.
</details> 

### 비교연산자(==)
- Reference type의 ==가 비교하는 것은 값이 아닌 객체
- primitive type의 ==가 실제 값을 비교하는 것과 반면...
  
<details>
 <summary>예시</summary>

  ```java
  Animal dog = new Animal(12);
  // dog ==> Animal@6acbcfc0

  Animal cat = new Animal(10);`
  // cat ==> Animal@3feba861

  Animal ref = cat;`
  // ref ==> Animal@3feba861

  Animal dog2 = new Animal(12);
  // dog2 ==> Animal@723279cf
  ```
</details>

</br>

## 2) String 클래스
- String은 사실, class의 instance이다!
- String은 불변 객체이다.
- 예시
  ```java
   public class StringRunner {

	    public static void main(String[] args) {
		   System.out.println("test".charAt(1)); // e
		
		   String s = "minji";
		
		   System.out.println(s.length()); // 5
		
		   System.out.println("kim ".concat(s)); //Kim minji 
		
		   System.out.println(s); // minji, String은 불변 객체
		
		   String[] array = "010-xyxy-dzz".split("-");
		
		   System.out.println("array[0] : " + array[0] + " , array[1] : " + array[1] + " ,     array[2] : " + array[2]);
	      } // array[0] : 010 , array[1] : xyxy , array[2] : dzz
    }
  ```

## 3) Wrapper 클래스
### Wrapper 클래스 등장 이유
- Wrapper class는 Primitive 자료형을 감싸서, Reference types으로 만든다.
- 즉, Primitive 자료형을 감싸, 객체 형태로 만들어, Primitive 자료형에서는 이용할 수 없었던 **메서드 이용**이 가능해진다.
  	``` java
   	Integer i1 = 5;
   	Integer i2 = Integer.valueOf(5);

   	i1.equals(i2); // true
   	```
### Types
- Wrapper : Boolean, Byte, Character, Double, Float, Integer, Long, Short
- Primitive : boolean, byte, char, double, float, int, long, short
### Wrapper class로 만드는 법 - 자동변환, valueOf()함수, 생성자
```java

Integer i1= 5; // 1

Integer i2 = Integer.valueOf(5); // 2

Integer i3 = new Integer(5); // 3

```
- 생성자 vs valueOf() 함수 중, 어느 것이 더 효율적? -> valueOf()
	- new 연산자를 이용해 매번 새로운 객체를 만들기보다는, </br>
          valueOf()메서드를 이용해 저장하는 값이 같다면, Heap 안에 존재하는 객체를 다시 사용.
- 어차피 자동변환되기에 1번 코드처럼 써도 됨.
### Wrapper class를 다시 Primitive class로 되돌리는 법 - 자료형Value(), 자동변환
``` java
Float f1 = Float.valueOf(5.0f);
		
float f2 = f1.floatValue();
		
Float f3 = 5.2f;
		
System.out.println(f3.equals(f2));
```
- 자동으로 변환해주기에, 자료형만 Float인지 float인지만 주의해주면 된다.
