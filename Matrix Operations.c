#include <stdio.h>
#include <stdlib.h>
#define dA(I,J) (*(dA + (I)*(c1) + (J)))
#define dB(I,J) (*(dB + (I)*(c2) + (J)))
#define dC(I,J) (*(dC + (I)*(c2) + (J)))
#define A(I,J) (*(A + (I)*(n) + (J)))
#define B(I,J) (*(B + (I)*(n) + (J)))
#define C(I,J) (*(C + (I)*(n) + (J)))
#define dD(I,J) (*(dD + (I)*(c1) + (J)))
#define dE(I,J) (*(dE + (I)*(r1) + (J)))
#define D(I,J) (*(D + (I)*(n) + (J)))
#define E(I,J) (*(E + (I)*(m) + (J)))
#define dT(I,J) (*(dT + (I)*(c2) + (J)))
#define T(I,J) (*(T+ (I)*(m) + (J)))
#define F(I,J) (*(F + (I)*(p) + (J)))
#define dF(I,J) (*(dF + (I)*(c2) + (J)))
void mat_add(int m, int n, double *A, double *B, double *C){
	int i,j;
	for( i=0; i<m; i++){
		for( j=0; j<n; j++){
			C(i,j)= A(i,j)+B(i,j);
		}
	}
}
void mat_mlt(int m, int n,int p, double *A, double *F, double *T){
	double sum;
	int i,j,z,s,y,k;
	 for(i=0; i<m; i++)
	 for(j=0; j<p; j++){
	 	sum=0.0;
	 	for(k=0; k<n; k++)
	 	sum+= A(i,k)*F(k,j);
	 	T(i,j)=sum;
	 }
             
}
void mat_trnsps(int m,int n, double *D, double *E){
	int i,j;
			 for( i=0;i<m;i++)
     {
      for( j=0;j<n;j++)
            {
                   E(j,i)=D(i,j);
            }
      }
		 	
	
}
 int main(){
 	int r1,r2,r3,c1,c2,c3,i,j;
 	double *dA,*dB,*dC,*dD,*dE,*dT,*dF;
 	int choose;
 	printf("1. Matrix Addition \n");
 	printf("2. Matrix Multiplication \n");
 	printf("3. Matrix Transpose \n");
 	printf("Please choose the matrix operation you want to do: ");
 	scanf("%d",&choose);
 	switch(choose){
 		
			case 1:
 	printf("Number of rows of the first operand matrix : ");
 	scanf("%d",&r1);
 	printf("Number of columns of the first operand matrix : ");
 	scanf("%d",&c1);
 	dA= (double*)malloc(r1*c1*sizeof(double));
 		printf("Content of the first operand matrix:\n");
 		for(i=0; i<r1; i++){
 		for(j=0; j<c1; j++){
 			scanf("%lf",&dA(i,j));
		 }
	 }
 		printf("Number of rows of the second operand matrix : ");
 	scanf("%d",&r2);
 		printf("Number of columns of the second operand matrix : ");
 	scanf("%d",&c2);
 	dB= (double*)malloc(r2*c2*sizeof(double));
 	printf("Content of the second operand matrix:\n");
 	 for(i=0; i<r2; i++){
 		for(j=0; j<c2; j++){
 			scanf("%lf",&dB(i,j));
		 }
	 }
		if (r1 != r2 || c1 != c2){
					printf ("The dimensions are not suitable for addition!");
				break;
			}
					else{
						c3=c1;
						r3=r1;
 	dC= (double*)malloc(r3*c3*sizeof(double));
 	printf("First Matrix: \n");
 		for(i=0; i<r1; i++){
		for(j=0; j<c1; j++){
			printf("%.2f\t",dA(i,j));
		}
		printf("\n");
	}
 	printf("Second Matrix: \n");
 		for(i=0; i<r1; i++){
		for(j=0; j<c1; j++){
			printf("%.2f\t",dB(i,j));
		}
		printf("\n");
	}
 	printf("Result: \n");
	 mat_add(r1,c1,dA,dB,dC);
		for(i=0; i<r1; i++){
		for(j=0; j<c1; j++){
			printf("%.2f\t",dC(i,j));
		}
		printf("\n");
	}
	 
	 free(dA);
	 free(dB);
	 free(dC);
	 break;	
}
    case 2:
    		printf("Enter the number of the rows of the first operand:");
	scanf ("%d", &r1);
	printf ("Enter the number of the columns of the first operand:");
	scanf("%d", &c1);
	dA= (double*)malloc (r1*c1*sizeof(double));
	printf("\n Content of the first matrix: \n");
	
	for (i=0;i<r1;i++) {
		for (j=0;j<c1;j++)
		scanf("%lf", &dA(i,j));
	}
	
	printf("Enter the number of the rows of the second operand:");
	scanf ("%d", &r2);
	printf ("Enter the number of the columns of the second operand:");
	scanf("%d", &c2);
	dF= (double*)malloc (r2*c2*sizeof(double));

	printf("\n Content of the second matrix: \n");
	int k,l;
	for (k=0;k<r2;k++) {
		for (l=0;l<c2;l++)
		scanf("%lf", &dF(k,l));
	}
	printf("Your first matrice:\n");
		for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                printf("%.2lf ",dA(i,j));
            }
            printf("\n");
        }
        printf("Your second matrice:\n");
	for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                printf("%.2lf ",dF(i,j));
            }
            printf("\n");
        }
	dT= (double*)malloc (r1*c2*sizeof(double));
	if ( c1 != r2){
		
	printf ("The matrix dimensions are not suitable for multiplication!");
}
else{
	printf("Result:\n");
		mat_mlt(r1,c1,c2,dA,dF,dT);
			for(i=0; i<r1; i++){
		for(j=0; j<c2; j++){
			printf("%.2f\t",dT(i,j));
		}
		printf("\n");
	}
	}
		
	 free(dA);
	 free(dB);
	 free(dT);
    	break;
	
	case 3:
	printf("Enter the number of the rows of the first operand:");
	scanf ("%d", &r1);
	printf ("Enter the number of the columns of the second operand:");
	scanf("%d", &c1);
	dD= (double*)malloc (r1*c1*sizeof(double));
	dE= (double*)malloc (r1*c1*sizeof(double));
	printf("\n Content of the first matrix: \n");
	int i,j;
	for (i=0;i<r1;i++) {
		for (j=0;j<c1;j++)
		scanf("%lf", &dD(i,j));
	}
	printf("Your matrice:\n");
		for(i=0; i<r1; i++){
		for(j=0; j<c1; j++){
			printf("%.2f\t",dD(i,j));
		}
		printf("\n");
	}
	printf("Transpoze:\n");
	mat_trnsps( r1, c1,dD,dE);
		for(i=0; i<c1; i++){
		for(j=0; j<r1; j++){
			printf("%.2f\t",dE(i,j));
		}
		printf("\n");
	}
	free(dD);
	free(dE);
	break;
		default:
		printf("Error");
		break;
}
 }
