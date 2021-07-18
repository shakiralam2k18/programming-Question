#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
int n,r;

struct frame
{
     char ack;
     int data;
}frm[10];

int sender(void);
void recvack(void);
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);
int main()
{
     int c;
     printf("Selective Reapeat ARQ \n");
     sender();
     recvack();
     resend_sr();
     printf("\nAll frames sent successfully");
}
int sender()
{
     int i;
     printf("\n Enter the no of frames to be sent:");
     scanf("%d",&n);
     for(i=1; i<=n;i++){
          printf("\nEnter data for frames [%d]",i);
          scanf("%d",&frm[i].data);
          frm[i].ack = 'y';
     }
     return 0;
}
void recvack()
{
     int i;
     rand();
     r = rand()%n;
     frm[r].ack = 'n';
     for(int i=1;i<=n;i++){
          if(i != r){
               printf("\n Data received for frm[%d]",i);
          }
     }
     for(i=1; i<=n; i++)
     {
          if(frm[i].ack == 'n')
               printf("\n The frame number %d is not received\n",r);
               break;
     }

}
void resend_sr()
{
     printf("\nresending frame %d",r);
     sleep(2);
     frm[r].ack = 'y';
     printf("\n The received frame is frm[%d]",r);
}
