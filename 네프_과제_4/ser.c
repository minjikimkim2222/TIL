#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h> // thread 관련 함수 헤더 추가

#define BUF_SIZE 100
#define MAX_CLNT 10

void * handle_clnt(void * arg); // 쓰레드가 처리할 함수
void send_msg(char * msg, int len, int clnt_num); // 메시지 전송 함수
void error_handling(char * msg); // 에러 처리 함수

int clnt_cnt=0; // 클라이언트 소켓이 접속한 수
int clnt_socks[MAX_CLNT]; // 클라이언트 소켓들 저장
pthread_mutex_t mutx; // 동기화 처리 방법 -> mutex 이용

int main(int argc, char *argv[])
{
    printf(">> Server started\n");
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_len;
	pthread_t t_id; // thread id 저장
	if(argc!=2) { // 서버의 포트번호를 인자로 받기
		printf("error, we need to input : %s <port>\n", argv[0]);
		exit(1);
	}
  
	pthread_mutex_init(&mutx, NULL); // mutex 객체 생성
	serv_sock = socket(PF_INET, SOCK_STREAM, 0); // 서버 소켓 생성

    // 주소 세팅
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET; // 주소 설정
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));
	
    // bind함수로 주소 바인딩
	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1) // 소켓 연결
		error_handling("error : bind() \n");
	if(listen(serv_sock, 5)==-1)
		error_handling("error : listen() \n");
	
    // while문
	while(1)
	{
		clnt_adr_len = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_len); // accept함수 -> connect완료
		
		pthread_mutex_lock(&mutx); // mutex lock
		clnt_socks[clnt_cnt++] = clnt_sock; // clnt배열에 accept된 client 소켓 저장
		pthread_mutex_unlock(&mutx); // mutex unlock
	
		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock); // thread 생성 -> 호출되는 함수 포인터 관찰
		pthread_detach(t_id); // 쓰레드 소멸
		printf(">> Accept connection from client\n");
	}
	close(serv_sock);
	return 0;
}
	
void * handle_clnt(void * arg)
{
	int clnt_sock = *((int*)arg); // 매개변수로 받은 client 소켓
	int str_len=0, i;
	char msg[BUF_SIZE];
	
    //72~88 까지 내용 추가!!!!!!! <-------------
     char nickname[BUF_SIZE]; // 닉네임을 저장할 변수

    // 클라이언트가 보낸 닉네임 정보를 받음
    str_len = read(clnt_sock, nickname, BUF_SIZE - 1);
    if (str_len <= 0) {
        close(clnt_sock);
        return NULL;
    }
    nickname[str_len] = '\0';

    pthread_mutex_lock(&mutx);
    clnt_socks[clnt_cnt++] = clnt_sock; // clnt배열에 accept된 client 소켓 저장
    pthread_mutex_unlock(&mutx);

    sprintf(msg, "[%s] is connected 여기 맞나?\n", nickname);
    send_msg(msg, strlen(msg), clnt_sock);
    //


	while((str_len=read(clnt_sock, msg, sizeof(msg)))!=0) // client에게 메시지를 받음
		send_msg(msg, str_len, clnt_sock); // 채팅 프로그램이니까, 다른 연결된 client들에게 메세지 전송 함수
	
	pthread_mutex_lock(&mutx);
	for(i=0; i < clnt_cnt; i++) // 연결된 client 해제 과정
	{
		if(clnt_sock == clnt_socks[i])
		{
			while (i < clnt_cnt - 1) {
				clnt_socks[i] = clnt_socks[i + 1];
				i++;
			}
			break;
		}
	}
    
	clnt_cnt--; // 클라이언트 접속 개수 1개씩 줄어듦
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);

    // 추가
    printf("[%s]가 채팅방을 떠났다.\n", nickname);
    //
	return NULL;
}

void send_msg(char * msg, int len, int clnt_num) // client들에게 메시지 전송
{
	int i;

	pthread_mutex_lock(&mutx);

	for(i=0; i < clnt_cnt; i++) // 클라이언트 수 만큼 메시지 전송
		if(clnt_num != clnt_socks[i]) // 전송한 client(자기 자신)은 제외해야 됨.
			write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mutx);
}

void error_handling(char * msg)
{
	fputs(msg, stderr);
	exit(1);
}