#include<stdio.h>

void print(const char*text) {
    int i;
    for(i=0; i<20; i++)
    {
        printf("Hello from %s\n", text);
        usleep(1000000);
    }
}


int main(){
   
 __pid_t pd= fork();
 if(pd==0)
 {
     __pid_t pd= fork();
     if(pd==0)
     {
         char * args[2]={"./friend" ,NULL};
         execvp(args[0] , args);
     }
     else
     {
         printf("child");
     }
 }

 else
 {
     printf("parent");
 }
 return 0;

}
