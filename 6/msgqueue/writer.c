#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAXMSGSIZE 50

struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;

void main()
{
	key_t key;
	int msgid;

	key = ftok("progfile" , 65);

	msgid = msgget(key , 0666|IPC_CREAT);
	message.mesg_type = 1;

	printf("Write the data: ");
	fgets(message.mesg_text , MAXMSGSIZE , stdin);

	msgsnd(msgid , &message , sizeof(message) , 0);

	printf("The data sent is: %s\n" , message.mesg_text);
}
