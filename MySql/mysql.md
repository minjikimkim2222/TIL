# MySQL
MySQL은 가장 널리 쓰이는 관계형 데이터베이스 관리 시스템.
  - MySQL에서 키워드, 구문, 문자열은 대소문자를 구분하지 않는다.
  - MySQL에서 테이블명과 필드의 이름은 대소문자를 구분한다.
  - MySQL에서 조작어 (CREATE, SELECT 등은) 대문자로, 그외 이름이나 칼럼에는 소문자를 추천.

## MySQL 기초 문법

### 데이터베이스 생성
```sql
CREATE DATABASE [데이터베이스명];
SHOW DATABASE;
``` 
- MySQL에서는 table을 만들려면, 먼저 사용할 Database를 만들어야 한다!
- 따라서, 기본적인 순서는 다음과 같다.
  - 데이터베이스 생성
  - 사용할 데이터베이스 선택
    ```sql
    USE [데이터베잉스명];
    ```
  - table 생성
