jsp 게시판에서 로그인 기능을 구현하려면, JSP 파일에서 회원 데이터베이스에 접근할 수 있도록 하는 **DAO(Data Access Object)**를 만들어야 한다. 

**DAO**는 데이터베이스 접근 객체의 약자이다. 데이터베이스의 정보를 불러올 때 사용한다.

# JDBC란?

자바 언어로 다양한 종류의 관계형 데이터베이스에 접속하고 SQL문을 수행하여 처리하고자 할 때 사용되는 표준 SQL 인터페이스 API이다.

JDBC는 자바의 표준 에디션에서 지원하는 기술로, 접속하려는 DBMS 서버에 따라서 JDBC 드라이버가 필요하다.

### JDBC driver 설치하기

[[JAVA] MySQL의 JDBC driver  설치하기](https://dhan-description.tistory.com/85)

# JDBC 구현하기

## 1. Connection - 접속

### 1-1. 드라이버 로딩

준비된 JDBC 드라이버 파일을 사용할 수 있도록, 메모리에 로딩해야 된다.

```java
Class.forName("com.mysql.cj.jdbc.Driver");
```

Class.forName()에 의해 JDBC 드라이버 파일의 드라이버 인터페이스를 상속한 클래스가 동적으로 로딩될 때, 자동으로 JDBC 드라이버 인스턴스가 생성되어 준비가 완료된다.

```java
public class TEST01 {
	public static void maid(String[] args){
		try {
			Class.forName("com.mysql.jdbc.Driver");
			System.out.println("드라이버 로딩 성공");
		}
		catch (ClassNotFoundException e) {
			System.out.println("[에러]" + e.getMessage());
		}
	}
}
```

### 1-2. 드라이버 연결

1-1에서 JDBC 드라이버를 로드했다면, 첫 번째 작업으로 DB서버와의 연결작업을 수행해야 한다. 

이 작업은 DriverManager 클래스의 getConnection()메서드를 사용한다.

```java
String url = "jdbc:mysql://localhost:3306/BBS"; // 프로토콜, 서버주소, 서버포트, DB이름
String user = "root"; // DB서버에 로그인할 계정
String password = "sample"; // DB서버에 로그인할 비밀번호

Connection conn = null;

conn = DriverManager.getConnection(url, user, password);
```

- JDBC URL의 형식은 "jdbc:프로토콜://서버주소:서버포트/DB이름”
- MYSQL 포트 번호 확인하기
    
    MYSQL 쿼리로 확인하기
    
    ```sql
    SHOW GLOBAL VARIABLES LIKE 'PORT';
    ```
    
- DriverManager.getConnection()는 실제 자바 프로그램과 데이터베이스를 네트워크상에서 연결해주는 메서드. 연결에 성공하면 DB와 연결된 상태를 Connection 객체로 표현해 반환한다.

```java
public class TEST02 {
	public static void main(String[] args){

		// 1. JDBC 드라이버 로딩
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			System.out.println("드라이버 로딩 성공");
		}
		catch (ClassNotFoundException e) {
			System.out.println("[에러]" + e.getMessage());
		}
	

		// 2. JDBC 드라이버 연결 - java코드와 데이터베이스 연결
		
		String url = "jdbc:mysql://localhost:3306/BBS"; // 프로토콜, 서버주소, 서버포트, DB이름
		String user = "root"; // DB서버에 로그인할 계정
		String password = "sample"; // DB서버에 로그인할 비밀번호

		Connection conn = null;

		try {
			conn = DriverManager.getConnection(url, user, password);
		}
		catch (SQLException e) {
			System.out.println("[에러]" + e.getMessage());
		}
	}
}
```


## 2. Statement와 PreparedStatement

앞선 과정에서 만든 Connection으로 자바 프로그램과 DB 사이에 연결이 되었다면, 이 연결을 통해 **자바 프로그램**은 DB 쪽으로 SQL문을 전송하고, **DB**는 처리된 결과를 다시 자바 프로그램쪽으로 전달해야 한다.

바로 이 기능을 하는 객체가 Statement, PreparedStatement이다.

두 가지 객체의 차이는

- Statement : 객체 생성 이후, sql문을 완성해 데이터베이스에 바로바로 처리하고
- PreparedStatement : 객체를 ‘?’가 포함된 sql문으로 생성하고, ‘?’자리만 바꿔가며 데이터베이스를 처리해간다.

### 2-1. 객체 생성

### Statement 객체 생성

- Connection 객체가 제공하는 createStatement() 메서드 사용

```java
Statement stmt = conn.createStatement();
```

### PreparedStatement 객체 생성

- Connection 객체가 제공하는 prepareStatement() 메서드를 사용하는데, 이때 인자값이 필요

```java
PreparedStatement pstmt = conn.prepareStatement(sql);
```

- prepareStatement()는 말그대로 ‘준비된 상태’이므로, 준비상태인 ‘?’가 들어간 String 타입의 sql문이 인자값이 되어야 한다.
    
    ```java
    String sql = "INSERT INTO dept2 VALUES(?,?,?)";
    PreparedStatement pstmt = conn.prepareStatement(sql);
    ```
    
- Statement 객체는 위의 작업은 나중에 한다. PreparedStatement 객체가 미리 하는 것이라 보면 된다.

## 2-2. SQL문 실행

앞선 과정에서 Statement, PreparedStatement 객체를 만들었다. 이제 Statement, PreparedStatement 객체를 이용해 DB서버로 sql문을 전송하고 처리 결과를 받아올 것이다. 

sql문을 실행하기 위해 객체에서 제공되는 메서드는 다음과 같다.

```java
ResultSet executeQuery(String sql)
// executeQuery()메서드가 반환하는 ResultSet은 select한 결과값을 가지고 있다
```

```java
int executeUpdate(String sql)
// executeUpdate()메서드가 반환하는 숫자값은 sql문 실행(update,delete,insert) 후, 영향을 받은 레코드의 개수이다.
```

이 두 메서드의 **차이점**은, 각각 SELECT문과 그 외의 SQL문(INSERT,UPDATE,DELETE 등)을 실행될 때 사용된다는 점에서 다르다!


<details>
  <summary>차이점 상세 설명</summary>
  
    1. **executeQuery() 메서드:**
        - 주로 SELECT 문을 실행할 때 사용됩니다.
        - 결과 집합(ResultSet)을 반환합니다.
        - 쿼리의 결과로 데이터베이스에서 데이터를 읽을 때 사용됩니다.
    
    ```java
    javaCopy code
    String sql = "SELECT column1, column2 FROM tableName";
    Statement statement = connection.createStatement();
    ResultSet resultSet = statement.executeQuery(sql);
    while (resultSet.next()) {
        // 결과 처리
    }
    
    ```
    
    1. **executeUpdate() 메서드:**
        - INSERT, UPDATE, DELETE와 같은 SQL 문을 실행할 때 사용됩니다.
        - 실행된 쿼리에 의해 영향받은 행의 수를 반환합니다.
    
    ```java
    javaCopy code
    String sql = "UPDATE tableName SET column1 = value1 WHERE condition";
    Statement statement = connection.createStatement();
    int rowsAffected = statement.executeUpdate(sql);
    // rowsAffected 변수에는 업데이트된 행의 수가 저장됨
    
    ```
    
    따라서, **`executeQuery()`**는 데이터를 읽고 가져오는 데 사용되며 **`ResultSet`**을 반환하고, **`executeUpdate()`**는 데이터를 변경하는(추가, 수정, 삭제) 데 사용되며 영향을 받은 행의 수를 반환합니다.
  
</details>

Statement 객체 sql문 실행은 인자값으로 sql문이 필요하다.

```java
ResultSet rs = stmt.executeQuery(sql);

int result = stmt.executeUpdate(sql); 
```

PreparedStatement 객체 SQL문은 인자값이 필요하지 않다. (인자값을 넣으면, 두 번 실행하는 꼴이 됨; 왜냐, 앞서 객체 생성할 때 미리 준비해서 ‘?’을 포함한 sql문을 넣었으니깐)

```java
ResultSet rs = pstmt.executeQuery();

int result = pstmt.executeUpdate();
```

### 참고, ResultSet이란?

ResultSet은 executeQuery()메서드에서 실행된 select문의 결과값을 가지고 있는 객체이다.

![image](https://github.com/minjikimkim2222/TIL/assets/96869808/d3129f59-9292-4b34-9bb1-d4316ff47b55)


ResultSet 객체가 가지고 있는 select 결과값은 ResultSet 객체의 메서드를 활용해 추출해 사용한다. 

Result 객체의 특징은 내부적으로 위치를 나타내는 커서(Cursor)의 개념이 있다는 것.

위의 그림처럼 next()메서드 등을 이용해 커서의 위치를 이동시킨다.
