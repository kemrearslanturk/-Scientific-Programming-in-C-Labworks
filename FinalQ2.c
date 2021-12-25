#include <stdio.h>
void EasySort(int arr[],int size){
    int min,i,j,k;
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
int arr[10]={3,4,1,5,6,2,9,8,1,2};
	int i;
	int j;
   int k;
    EasySort(arr,10);
     for( k=0;k<10;k++){
        printf("%d ",arr[k]);
    }
   
}

