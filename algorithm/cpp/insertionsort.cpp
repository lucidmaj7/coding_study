#include <stdio.h>


#define ARR_LEN 10
int arr[ARR_LEN] = {10,23,4,1,6,100,5,3,7,2};

void printArr()
{
	for(int i = 0 ;i<ARR_LEN;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	

}

void insertionSort()
{
	for(int i = 1 ;i<ARR_LEN ;i++)
	{

		int j = i;
		while(j>=0 && arr[j] < arr[j-1])
		{
			
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
			printArr();
		}

		printf("-------\n");	
	}
	

}

int main(void)
{
	printArr();
	
	insertionSort();

	printArr();

	return 0;
}
