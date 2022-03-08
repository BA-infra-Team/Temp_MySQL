# Temp_MySQL
C MySQL API 활용 연습 및 MySQL 기본 사용법 및 문법 정리 

### 우분투 MySQL 환경 구축 
1. `sudo apt-get install mysql-server -y` // mysql 서버 설치  
2. `sudo mysql_secure_installation`  // mysql 보안 설정 설치  
3. `sudo systemctl enable --now mysql.service` // mysql 서버 활성화  
4. `sudo systemctl status mysql.service` // mysql 서버 상태 확인  
5. `sudo ufw status` // 서버 포트 상태 확인  
6. `sudo ufw allow mysql` // mysql 포트 허용  
7. `sudo mysql -u root -p mysql` // mysql 포트 허용  

관령 링크 : https://www.youtube.com/watch?v=3qD6zv7thdE  
### 클라이언트 설치 및 커넥션 (C MySQL API)
`gcc -o createdb $(mysql_config --cflags) createdb.c $(mysql_config --libs)` // 컴파일 명령어 
`sudo apt install default-libmysqlclient-dev` // c 예제를 컴파일 위한 MySQL C 개발 라이브러리 설치

MySQL C API 활용 예제 링크 : https://zetcode.com/db/mysqlc/  
### MySQL 기본 문법 정리
`SHOW DATABASES;` // 현재 DB 목록 보기  
`CREATE DATABASES mydatabase;` // mydatabase라는 이름의 DB를 만듬   
`USE mydatabase;` // mydatabase DB 사용
`DESC tablename;` // 테이블 구조 보기  
`DESCRIBE tablename;` // 테이블 구조 보기  
`CREATE TABLE logdatas(
	->job_id INT NOT NULL,
	->job_status VARCHAR(50)
);` // 테이블 만들기 
`CREATE USER user12@localhost IDENTIFIED BY '34klq*222';` // USER를 만듬  
`GRANT ALL ON testdb.* to user12@localhost;` // testdb 에 대해 user12에게 모든 권한을 부여  

`LOAD DATA LOCAL INFILE "/home/ubuntu/Workspace/LogData2.csv" INTO TABLE logdatas FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS;` // csv to DB

### 겪은 문제점들 
1. csv to mysql  
- `LOAD DATA LOCAL INFILE "/home/ubuntu/Workspace/LogData2.csv" INTO TABLE logdatas FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 ROWS;` // csv to DB, LOCAL 로 해결   
3. mysql conf 관련  
- 아직 잘 모르겠음.  
5. 한글 깨짐 문제  
- `ALTER DATABASE databasename CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;` // DB를 utf-8로 설정  
- `ALTER TABLE tablename CONVERT TO CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;` // Table 속성을 utf8로 설정  
- 설정 먼저하고 데이터를 넣어야 함.  
