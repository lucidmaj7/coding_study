#include <stdio.h>


#define ARR_LEN 10
int arr[ARR_LEN] = {10,23,4,1,6,100,5,3,7,2};

void selectionSort()
{
	for(int i = 0 ;i < ARR_LEN;i++)
        {

                int curMinIdx  = i;
                for(int j = i;j<ARR_LEN;j++)
                {
                        if(arr[curMinIdx ]>  arr[j])
                        {
                                curMinIdx = j;
                        }

                }
                int temp = arr[curMinIdx];
                arr[curMinIdx] =arr[i];
                arr[i] = temp;
        }



}

int main(void)
{

	for(int i = 0 ;i<ARR_LEN;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	selectionSort();

	for(int i = 0 ;i<ARR_LEN;i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\n");

	return 0;
}
