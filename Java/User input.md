# User input 방법 : Scanner클래스
사용법
``` java

import java.util.Scanner;

public class UserInputRunner {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int i = input.nextInt();
		System.out.println("int : " + i);
		
		double d = input.nextDouble();
		System.out.println("double : " + d);
		
		boolean isTrue = input.nextBoolean();
		System.out.println("boolean : " + isTrue);
		
		float f = input.nextFloat();
		System.out.println("float : " + f);

	}

}

```
- Scanner도 객체니까 new 연산자와 메서드 쓸 것!
