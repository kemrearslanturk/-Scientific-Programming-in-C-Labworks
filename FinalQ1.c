#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int i,j;
	int r,h,k;
	r=10;
	k=30;
	h=30;
	for(i=0; i<60; i++){
		
		for(j=0; j<60; j++){
			
				if((i-h)*(i-h)+(j-k)*(j-k)<r*r){
				
				printf("* ");
				
			}
			
			else{
				
			printf("/ ");
		}
		/*
		If i have enough time, I will check row have intersection point with circle. if row have circle, i can print '.' for left and right of circle, 
		from upper point of circle to middle of circle and every row increasing column of '.' step by step. 
		After middle of circle i can printf '.' decreasing step by step every row.
		*/
		}
		printf("\n");
	}
}
