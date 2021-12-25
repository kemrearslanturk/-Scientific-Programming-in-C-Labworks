#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float fro(float* a, int Nrows, int Ncols)
{
	int i,j;
    float toplam = 0.0;
    float value, sonuc;
    for(i=0; i<Nrows;i++)
    {
        for(j=0;j<Ncols;j++)
        {
        	
        	
            value = 	*(a + (i*Ncols) + j);
            
            toplam +=	 value * value;
        }
    }
    
    sonuc= sqrt(toplam);
    
    return sonuc;
}

int main(){
	int row,col,i;
	float *array;
	printf("\nEnter   col:"); scanf("%d", &col);
	printf("\nEnter row :"); scanf("%d",&row);
	
	array =(float*)malloc(row*col*sizeof(float));
	
	printf("\nEnter elements of a matrix:");
	
	while(i<row*col){
			scanf("%f",&array[i]);
			i++;
	}
	
	printf("\n Result= %f\n",fro(array,row,col));
	
}
