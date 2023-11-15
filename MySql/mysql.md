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

### 테이블 생성
```sql
CREATE TABLE [테이블명];
```
```sql
CREATE TABLE professor
(
  id INT PRIMARY KEY,
  name VARCHAR(32) NOT NULL,
  phone VARCHAR(32)
);
DESCRIBE professor;
```
  - primary key 특징 : 데이터베이스 테이블마다 각 행을 고유하게 식별해주는 열
    - 고유성 : 테이블 내의 각 행마다 유일해야 한다. 즉, 어떤 두행에서도 동일한 키값을 가질 수 없다.
    - NOT NULL

### 데이터 삽입 (INSERT)
```sql
INSERT INTO professor
(id, name, phone(
VALUES ('19', '현지', '01112344555');
```

### 데이터 검색 (SELECT)
- SELECT 뜻
  - 원하는 데이터의 칼럼을 선택하거나, 레코드의 순서 지정 가능

```sql
SELECT * FROM professor;
SELECT * FROM professor ORDER BY id;
```

### 데이터 조건 선택 (WHERE)
```sql
SELECT id,name FROM professor WHERE id = '19';
SELECT * FROM professor WHERE id >= 19 AND id < 23;
SELECT * FROM professor WHERE id > 20 OR id < 23;
```
