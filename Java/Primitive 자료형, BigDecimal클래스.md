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
