#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

typedef struct _TEST_CASE{
	int n;
	int m;
	int isFriends[MAX_N][MAX_N]; 
	int isTaken [MAX_N] ;
}TEST_CASE,*PTEST_CASE;

int nCase= 0;
PTEST_CASE tc = NULL;

int countPairing(PTEST_CASE pTc)
{
	int nFirst = -1;
	int nRet =0;
	for(int i=0;i<pTc->n; i++)
	{
		if(pTc->isTaken[i]==0)
		{
			nFirst = i;
			break;
		}
	}

	if(nFirst== -1)
	{
		return 1;
	}

	for(int nPair = nFirst+1; nPair < pTc->n ;nPair++)
	{
		if(pTc->isTaken[nPair]==0 && (pTc->isFriends[nFirst][nPair] ==1) )
		{
			pTc->isTaken[nFirst]= pTc->isTaken[nPair]= 1;
			nRet += countPairing(pTc);
			pTc->isTaken[nFirst]= pTc->isTaken[nPair]= 0;
		}
		
	}

	return nRet;
}

int main(void)
{

	scanf("%d", &nCase);
	tc = (PTEST_CASE)malloc(sizeof(TEST_CASE)*nCase);
	for(int i=0; i<nCase;i++)
	{
		scanf("%d %d", &tc[i].n ,&tc[i].m);
		
		for(int j=0;j<tc[i].n;j++)
		{
			
			for(int k=0;k<tc[i].n;k++)
				tc[i].isFriends[j][k]=0;
		}
		for(int j=0;j<tc[i].m;j++)
		{
			int a,b;
			scanf("%d %d ",&a,&b );
			tc[i].isFriends[a][b] = 1;
			tc[i].isFriends[b][a] = 1;
		}

	}

	for(int i=0;i< nCase ;i++)
	{	
		for(int j=0;j<tc[i].n;j++)
		{
			tc[i].isTaken[j]=0;

		}
		printf("%d\n",countPairing(&tc[i]));
	

	}

	return 0;
}
