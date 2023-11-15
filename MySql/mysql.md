# MySQL
MySQL은 가장 널리 쓰이는 관계형 데이터베이스 관리 시스템.
  - MySQL에서 키워드, 구문, 문자열은 대소문자를 구분하지 않는다.
  - MySQL에서 테이블명과 필드의 이름은 대소문자를 구분한다.
  - MySQL에서 조작어 (CREATE, SELECT 등은) 대문자로, 그외 이름이나 칼럼에는 소문자를 추천.

## MySQL 기초 문법

### 데이터베이스 생성
```sql
CREATE DATABASE [데이터베이스명];
SHOW DATABASES;
``` 
- MySQL에서는 table을 만들려면, 먼저 사용할 Database를 만들어야 한다!
- 따라서, 기본적인 순서는 다음과 같다.
  - 데이터베이스 생성
  - 사용할 데이터베이스 선택
    ```sql
    USE [데이터베이스명];
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
### 조건 검색, 효율적인 방법 (BETWEEN, IN)
```sql
SELECT * FROM professor
WHERE id BETWEEN 19 AND 23;
```
```sql
SELECT * FROM professor
WHERE id IN (19,22,23); //id가 19 or 22 or 23인 행만 선택할 것
```

### 데이터베이스, 테이블 삭제(DROP, DELETE)
- 데이터베이스와 테이블 제거 - DROP
- 테이블의 데이터 제거 = DELETE
  - 특히 테이블의 데이터를 삭제할 때는 SELECT를 통해 조건을 주어 삭제할 수도 있다.

```sql
DROP DATABASE [데이터베이스명];
DROP TABLE [테이블명];
```
```sql
DELETE FROM [테이블명];
DELETE FROM professor where id = '19';
```

### 테이블 변경 (ALTER)
테이블 변경은 아래의 4가지 일을 할 수 있다.
#### 1. 테이블 이름 변경 (RENAME)
```sql
ALTER TABLE professor
RENAME TO student;
```

#### 2. 데이터 칼럼, 제약조건 추가 (ADD)
```sql
ALTER TABLE student
ADD COLUMN gender CHAR NOT NULL;

ALTER TABLE student
ADD PRIMARY KEY (id); // 기존에 존재하는 id 칼럼에 PRIMARY KEY 속성 추가
```

#### 3. 테이블 변경 (CHANGE, MODIFY)
```sql
ALTER TABLE student
MODIFY COLUMN phone varchar(30) DEFAULT 010;
```
- 여기서 MODIFY를 CHANGE로 바꿔서 써도 된다.
- MODIFY와 CHANGE는 모두 테이블의 칼럼의 상태를 변경해주지만, </br>
  CHANGE는 칼럼의 이름도 변경이 가능하다.

#### 4. 테이블 제약조건 제거 (DROP)
```sql
ALTER TABLE student
DROP COLUMN gender,
DROP PRIMARY KEY;
```

### 테이블 변경 (UPDATE)
- 테이블에 데이터를 수정할 때 사용

```sql
UPDATE [테이블] SET [column] = '변경할 값' WHERE [조건];
```

### 생성문 보기 (SHOW)
```sql
SHOW CREATE DATABASE [데이터베이스명];
SHOW CREATE TABLE [테이블명];
```
