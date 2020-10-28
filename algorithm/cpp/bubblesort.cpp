#include <stdio.h>

#define MAX_VAL 9999999
#define ARR_LEN 10
int arr[ARR_LEN] = {10,23,4,1,6,100,5,3,7,2};

void boubleSort()
{	
	for(int i = 0 ;i < ARR_LEN;i++)
	{
		 
		for(int j = 0;j<ARR_LEN-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}	
		}
	}


}

int main(void)
{

	for(int i = 0 ;i<ARR_LEN;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	boubleSort();
	for(int i = 0 ;i<ARR_LEN;i++)
        {
		printf("%d ", arr[i]);
        }
        printf("\n");

	return 0;
}
