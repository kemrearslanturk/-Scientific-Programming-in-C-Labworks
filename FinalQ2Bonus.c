#include <stdio.h>
#include<time.h>
void EasySort(int arr[],int size){
    int min,i,j,k;
     srand(time(NULL));
    int temp;
    for(i=0; i<size;i++){
        min = i;
        for(j=i+1;j<size;j++)
           if(arr[j]>arr[min]) min = j;

      temp = arr[min];
      arr[min]=arr[i];
      arr[i]= temp;
      
    }
}



int main (){
int arr[10];
 srand(time(NULL));
	int i;
	int j;
	 for(i=0;i<8;i++){
	   arr[i]=rand()%25;
	 }
   
    EasySort(arr,10);
    for(i=0; i<10; i++){
    	j=arr[i];
    	for(j; j>0; j--){
		
    	printf("*");
    }
    printf("\n");
	}
}
