
//https://algospot.com/judge/problem/read/CLOCKSYNC
#include <stdio.h>
#include <algorithm>
#define INF 9999
#define MAX_SWITCH 10

int switchs[MAX_SWITCH][5]={-1,};

void initSwitchs()
{
    int i=0;
    int j=0;
    switchs[i][j++]=0;
    switchs[i][j++]=1;
    switchs[i][j++]=2;
     switchs[i][j++]=-1;
    i++;
    j = 0;
    switchs[i][j++]=3;
    switchs[i][j++]=7;
    switchs[i][j++]=9;
    switchs[i][j++]=11;
       switchs[i][j++]=-1;
    i++;
    j = 0;
      switchs[i][j++]=4;
      switchs[i][j++]=10;
     switchs[i][j++]=14;
     switchs[i][j++]=15;
        switchs[i][j++]=-1;

     i++;
    j = 0;
    switchs[i][j++]=0;
    switchs[i][j++]=4;
   switchs[i][j++]=5;
    switchs[i][j++]=6;
     switchs[i][j++]=7;
       switchs[i][j++]=-1;
     i++;
    j = 0;
     switchs[i][j++]=6;
     switchs[i][j++]=7;
     switchs[i][j++]=8;
     switchs[i][j++]=10;
     switchs[i][j++]=12;
   switchs[i][j++]=-1;
     i++;
    j = 0;
     switchs[i][j++]=0;
     switchs[i][j++]=2;
     switchs[i][j++]=14;
     switchs[i][j++]=15;
        switchs[i][j++]=-1;
    i++;
    j = 0;
     switchs[i][j++]=3;
     switchs[i][j++]=14;
     switchs[i][j++]=15;
        switchs[i][j++]=-1;
          i++;
    j = 0;
     switchs[i][j++]=4;
     switchs[i][j++]=5;
     switchs[i][j++]=7;
     switchs[i][j++]=14;
     switchs[i][j++]=15;
   switchs[i][j++]=-1;
     i++;
    j = 0;
     switchs[i][j++]=1;
     switchs[i][j++]=2;
     switchs[i][j++]=3;
     switchs[i][j++]=4;
     switchs[i][j++]=5;
   switchs[i][j++]=-1;
    i++;
    j = 0;
    switchs[i][j++]=3;
    switchs[i][j++]=4;
    switchs[i][j++]=5;
    switchs[i][j++]=9;
    switchs[i][j++]=13;
   switchs[i][j++]=-1;
        

}


int checkClock(int* clocks)
{

    for(int i=0;i<16;i++)
    {
        if(clocks[i]!=12)
        {
            return 0;
        }

    }
    return 1;
}
void push(int* clocks, int selswitch)
{   
    for(int i=0;i<5;i++)
    {
        if(switchs[selswitch][i] == -1)
        {
            break;
        }
        clocks[switchs[selswitch][i]]+=3;
        if(clocks[switchs[selswitch][i]]==15)
        {
            clocks[switchs[selswitch][i]]=3;
        }
    }


}
int clocksync(int* clocks,int selswitch)
{
    int ret=INF;

    if(selswitch==MAX_SWITCH)
    {
        if(checkClock(clocks)==1)
            return 0; 
        else 
             return INF;
    }
    
    for(int i=0;i<4;i++)
    {
        ret=std::min(ret,i+clocksync(clocks,selswitch+1));
        push(clocks,selswitch);
      
    }

    return ret;
}



int main(void)
{
    int testcase =0;
    initSwitchs();

    scanf("%d\n",&testcase);

    for(int i=0;i<testcase;i++)
    {
        int clocks[16]={0,};
        for(int j=0;j<16;j++)
        {
            scanf("%d ",&clocks[j]);
        }
        int ret =clocksync(clocks,0);
      
        printf("%d\n",   ret==INF ? -1 : ret);
    }


    return 0;

}