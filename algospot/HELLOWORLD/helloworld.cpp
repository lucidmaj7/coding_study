// https://algospot.com/judge/problem/read/HELLOWORLD

#include <stdio.h>



int main(void)
{

    int ncase = 0;
  
    scanf("%d\n", &ncase);
    for(int i=0;i<ncase;i++)
    {
        char temp[50]={0,};
        scanf("%s\n", temp);
        printf("Hello, %s!\n", temp);
        
    }
    return 0;


}