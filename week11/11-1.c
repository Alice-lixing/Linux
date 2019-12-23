#include "my.h"
int main()
{
   pid_t r;
   int r_num;
   int pipefd[2];
   char buf[1];
   memset(buf,0,sizeof(buf));
   if(pipe(pipefd)<0)
      {
             perror("pipe failed.\n");
             return -1;
      
      }
   r=fork();
   if(r<0)
     {
        perror("fork failed.\n");
        return -1;
     }
    else if(r==0)
     {
        char b='a';
        close(pipefd[0]);
        //sprintf(w_buf,"pid=%d",getpid());        
        for(int  i =0;i<65537;i++)
               {
                 printf("child write %d times.\n",i);
                 write(pipefd[1],&b,1);
               }
        printf("child write ok.\n");
        close(pipefd[1]);
         exit(0);

 
     }
     else
    {
        wait(NULL);
        close(pipefd[1]);
            for(int  i =0;i<65536;i++)
                  {
                    read(pipefd[0],buf,1);
                    printf("%d:parent read from pipe: %s\n",i,buf);
                  }
         close(pipefd[0]);


       
        return 0;
           }
}

