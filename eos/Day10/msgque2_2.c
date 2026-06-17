#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MSG_KEY 0x1234

struct msgbuf{
		long mtype;
		char mtext[20];
};

int main(void)
{
		int msgid = msgget(MSG_KEY, IPC_CREAT | 0600);
		if(msgid == -1)
		{
				perror("msgget() is failed");
				_exit(-1);
		}

		// receive msg from msg queue
		printf("waiting for message ....\n");
		struct msgbuf m2;
		int ret = msgrcv(msgid, &m2, sizeof(m2.mtext), 11, 0);
		if(ret == -1)
		{
				perror("msgrcv() is failed");
				_exit(-1);
		}
		printf("Received MSG = %s\n", m2.mtext);
		
		// write msg into msg queue
		struct msgbuf m1;
		m1.mtype = 22;
		printf("Enter string : ");
		scanf("%[^\n]s", m1.mtext);
		ret = msgsnd(msgid, &m1, sizeof(m1.mtext), 0);
		if(ret == -1)
		{
				perror("msgsnd() is failed");
				_exit(-1);
		}
		printf("MSG is sent successfully !!!\n");

		msgctl(msgid, IPC_RMID, NULL);

		return 0;
}














