//https://algospot.com/judge/problem/read/URI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 80



char getSpacialChar(char* en)
{

	char temp[4]= {0,};
	memcpy(temp, &en[1],2);
		
	int a=	strtol(temp, NULL,16);

	return a;
	


}

void decode(char* enc)
{

//rintf("%s\n",enc);
	int len = strlen(enc);
	for(int i = 0 ; i<len; i++)
	{
		if(enc[i] == '%' && enc[i+1] !='%' && i+2 <len )
		{
			char temp = getSpacialChar(&enc[i]);	
			if(temp!=0)
			{
				enc[i]=temp;
				
				printf("%c", enc[i]);
				i++;
				i++;
			}else
			{
				printf("%c", enc[i]);
			}
		}
		else
			printf("%c", enc[i]);
	}

	return;

}
int main(void)
{
	int ncase = 0;
	char** encodedstr = NULL;
	scanf("%d\n", &ncase);
	
	encodedstr = (char**)malloc(sizeof(char*)*ncase);


	for(int i=0;i<ncase;i++)
	{	
		encodedstr[i]=(char*)malloc(sizeof(char)*MAX_LEN);
		memset(encodedstr[i], 0x00, MAX_LEN);
		scanf("%s\n", encodedstr[i]);
		decode(encodedstr[i]);
		printf("\n");
	
}
}
	

