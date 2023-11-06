# 1. Primitive 자료형과 BigDecimal 클래스
Premitive 자료형은 다른 언어와 거의 비슷하다. </br>
따라서 BigDecimal 위주로 정리해보았다. </br>
## 1) Premitive 자료형
- 각 값의 범위에 맞는 변수를 사용하자.
### integer
``` java
byte b = 127;
short s = 32767;
int i = 2147483647; // 21억
long l = long l = 9223372036854775807L; // 모든 literal은 기본적으로 int, double 취급을 하기에 L을 붙여줌.

```
### floating point
``` java
float f = 45.fF; // 모든 literal은 기본적으로 int,double 취급하기에
double = 45.f;

```
### boolean
``` java
boolean isTrue = true; // boolean값은 int형 허용 안 함, 오직 true, false만 가능.

```
### character
``` java
char c = 'a';

```

## 2) BigDecimal 클래스
### 1. BigDecimal 클래스 등장 이유
- 실수값을 계산할 때, float나 double형을 쓰면 오차가 발생한다. </br>
- 따라서, 정확한 실수값 계산을 위해서는 **자바**에 **내장**된 클래스인 BigDecimal 클래스를 이용할 것!
### 2. 사용법
``` java
import java.math.BigDecimal;

public class BigDecimalRunner {

	public static void main(String[] args) {

		BigDecimal num1 = new BigDecimal("34.56789876");
		BigDecimal num2 = new BigDecimal("32.2332");
		
		BigDecimal num3 = num1.add(num2);
		
		System.out.println(num3);
	}

}

```
- BigDecimal은 "클래스"이다.
  - 그렇기에, '+' 연산자의 피연산자에 해당하지 않으므로, add메서드 사용.
- 보다 정확한 계산을 원한다면 파라미터값은 double이 아닌 **string**을 이용할 것.
### 3. 주의사항
#### BigDecimal "메소드"들은 오직 BigDecimal 클래스형만 지원한다.
``` java
// 배열값의 평균 구하기

import java.math.BigDecimal;
import java.math.RoundingMode;

public class BigDecimalRunner {

	public static void main(String[] args) {
		int[] arr = {100, 1200, 30};
		
		int sum = 0;
		for (int i = 0; i < arr.length; i++) {
			sum += arr[i];
		}
		
		BigDecimal average;
		
		average = (new BigDecimal(sum).divide( new BigDecimal(arr.length), 5, RoundingMode.UP));
		
		System.out.println(average);
	}
}


```
- new 연산자를 통해 BigDecimal 클래스의 객체를 만들 때는 상관없는데, </br>
  메서드 divide를 이용할 때는 오직 BigDecimal 클래스형만 지원한다.
- 5, RoundingMode.up
  - 이거 안해주면, 463.3333333.. 과 같이 저장되어 에러 발생.
  - 따라서, 소수점 몇자리까지를 나타낼지(5), 반올림할지 안할지(UP/DOWN)을 결정해야 함.
