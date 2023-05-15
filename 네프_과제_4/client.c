#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
	
#define BUF_SIZE 100
#define NAME_SIZE 20 // 클라이언트를 식별할 사용자 이름
	
void * send_msg(void * arg); // 메시지 send 함수
void * recv_msg(void * arg); // 메시지 recv 함수
void error_handling(char * msg);
	
char user_name[NAME_SIZE]="";
char msg[BUF_SIZE];
	
int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;

	if(argc!=4) { // IP주소, 포트번호, 이름을 인자로, 마지막 이름으로 각각 클라이언트 식별 가능
		printf("error, we need to input : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	 }
	
	sprintf(user_name, "[%s]", argv[3]);

	sock=socket(PF_INET, SOCK_STREAM, 0); // socket 생성
	
    // 서버 socket 주소 설정
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET; 
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	
    // connect 함수
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1) // 소켓 연결
		error_handling("error : connect()\n");

	printf("채팅 서버에 연결되었습니다.\n");
    /*
    이 부분 수정
    // */
    char send_user_name[BUF_SIZE] = {0};
    strcpy(send_user_name, argv[3]);
    write(sock, send_user_name, strlen(send_user_name));
    ///////
    printf("%s 님이 입장했습니다.\n", send_user_name); // 추가
	//
	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock); // thread 생성, send_msg함수로!
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	pthread_join(snd_thread, &thread_return); //thread_join 함수로 순서를 기다리게 함!
	pthread_join(rcv_thread, &thread_return);
	close(sock);  
	return 0;
}

void * send_msg(void * arg) // send_msg, 서버와 연결된 소켓을 받아, 서버에게 입력한 문자열 보내기
{
	int sock = *((int*)arg);

	char name_msg[NAME_SIZE + BUF_SIZE];

	while(1) 
	{
		fgets(msg, BUF_SIZE, stdin); // stdin(키보드)로부터 입력받기
		sprintf(name_msg,"%s %s", user_name, msg); // user_name과 msg를 결합한 name_msg를 write로 서버에게 보내기
		write(sock, name_msg, strlen(name_msg));
	}
	return NULL;
}

void * recv_msg(void * arg) // recv_msg함수, 각 클라이언트 창에서 서버로부터 받은 메세지 출력
{
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE + BUF_SIZE];

	int str_len;
	while(1)
	{   
		str_len = read(sock, name_msg, NAME_SIZE+BUF_SIZE-1); // 서버에 연결된 클라이언트로부터 메세지 읽어들임
		if(str_len==-1) 
			return (void*)-1; // 에러
		name_msg[str_len]=0;
		fputs(name_msg, stdout); // 해당 받은 문자열을 터미널에 출력
	}
	return NULL;
}

void error_handling(char *msg) // 에러처리 함수
{
	fputs(msg, stderr);
	exit(1);
}