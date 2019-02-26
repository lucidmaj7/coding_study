//https://algospot.com/judge/problem/read/BOARDCOVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _TEST_CASE{

    int h;
    int w;
    char board[20][20];
    char temp_board[20][20];
}TEST_CASE,*PTEST_CASE;

bool set(PTEST_CASE tc, int x,int y,int type)
{      
    
    if(type==0)
    {
    
        if( tc->temp_board[y][x] == '.' && tc->temp_board[y][x+1] =='.' && tc->temp_board[y+1][x] =='.')
        {
            tc->temp_board[y][x] = '#';
            tc->temp_board[y][x+1] = '#';
            tc->temp_board[y+1][x] = '#';
            return true;
        } 
    }
    if(type==1)
    {
       
        if( tc->temp_board[y][x] == '.' && tc->temp_board[y][x+1] =='.' && tc->temp_board[y+1][x+1] =='.')
        {
            tc->temp_board[y][x] = '#';
            tc->temp_board[y][x+1] = '#';
            tc->temp_board[y+1][x+1] = '#';
           
            return true;
        } 
    }

    if(type==2)
    {
        if( tc->temp_board[y][x] == '.' && tc->temp_board[y+1][x] =='.' && tc->temp_board[y+1][x+1] =='.')
        {
            tc->temp_board[y][x] = '#';
            tc->temp_board[y+1][x] = '#';
            tc->temp_board[y+1][x+1] = '#';
           
            return true;
        } 
    }

    if(type==3)
    {

        if( tc->temp_board[y][x] == '.' && tc->temp_board[y+1][x] =='.' && tc->temp_board[y+1][x-1] =='.')
        {
             tc->temp_board[y][x] = '#';
            tc->temp_board[y+1][x] = '#';
            tc->temp_board[y+1][x-1] = '#';
           
            return true;
        } 
    }



    return false;
}

int boardcover(PTEST_CASE tc)
{
    int nRet = 0;
    int startx= -1;
    int starty= -1;
    for(int i=0;i< tc->h; i++ )
    {
        for(int j=0;j<tc->w;j++)
        {
            if(tc->temp_board[i][j]=='.')
            {
                starty=i;
                startx=j;
                break;
            }
        }
        if(starty != -1)
            break;
    }
    if(starty == -1 )
    {    
        return  1;
    }

    for(int type=0;type<4;type++)
    {
        char temptempboard[20][20]={0,};
        memcpy(temptempboard, tc->temp_board,20*20);
        if(set(tc,startx,starty,type))
        {
        
            nRet =nRet+ boardcover(tc);
        }
        memcpy(tc->temp_board, temptempboard, 20*20);
    }

    return nRet;
}

int main(void)
{
    PTEST_CASE tc = NULL;
    int nTestCase=0;
    scanf("%d\n", &nTestCase);

    tc = (PTEST_CASE)malloc(sizeof(TEST_CASE)*nTestCase);

    for(int i=0; i<nTestCase;i++)
    {
        scanf("%d %d\n", &tc[i].h, &tc[i].w);
      
        for(int j=0;j<tc[i].h;j++)
        {
            scanf("%s",tc[i].board[j]);
         
        }
        memcpy(tc[i].temp_board,tc[i].board,20*20);
       
        printf("%d\n", boardcover(&tc[i]));
    }

    

    return 0;
}