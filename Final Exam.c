#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

double func(double x){
	double result;
	result=sin((PI/2)*x*x)+0.2;
	return result;
	
}
void printArray(double inputArray[50]){
	int i=0;
	while(inputArray[i]!=0){
		printf("%f\n",inputArray[i]);
		i++;
	}
}

int isRootPresent(double t_low, double t_upp){
	if(func(t_low)*func(t_upp)<0){
		return 1;
	}
	else {
	return 0;
}
}
void findLowerBoundaries(double lower_boundaries[50],double a,double b){
	double i=0;
	int j,j2;
	for(i=a; i<b; i=i+0.05){
		 if(isRootPresent(i,i+0.05)==1){
			lower_boundaries[j]=i;
			j++;
		}
	}
	
}
double bisect(double x1,double x2, double epsilon ){
double y;
for(y=(x1+x2)/ 2.0 ; fabs(x1-y)>  epsilon; y = (x1+x2)/2.0)
if(func(x1)*func(y) <= 0.0)
x2=y;
else
x1=y; 
return(y);

}
void findRoots(double (*f)(double),double lower_boundaries[50],
double roots[50], double epsilon){
	 int i=0;  double lowvalue,upvalue;
    for(;lower_boundaries[i]!=0.0;){
        lowvalue = lower_boundaries[i];
        upvalue = lowvalue + 0.05;
        
        
        roots[i]= bisect(lowvalue,upvalue,epsilon); i++;
    }
}
double leftRectangle(double (f)(double), double x1, double x2, double step){
	
        double toplam = 0.0;

        while(x1<x2){
        	
            toplam=toplam+(func(x1)*step);
            
			x1=x1+step;
        }
        return toplam;
    }
    
void saveIntegrals(double roots[50],double integrals[50],double a,double b,double step){
    int j=0;
    while(1){
    	
        if(roots[j]==0){
        	
            break;
            
        }
        
        integrals[j]	=	leftRectangle(func,a,roots[j],step);
        a	=	roots[j];
        
        j++;
    }
integrals[j]=leftRectangle(func,a,b,step);
}
getMaxIntegral(double integrals[50],double a,double b,double step,double results[50]){
	
}

int main(){
	printf("Test for f(0.0 )%f\n",func(1.50));
	printf("Test for f(2.20 )%f\n",func(2.20));
	printf("Result for isRootPresent(1.95,2): %d\n",isRootPresent(1.95,2));
	printf("Result for isRootPresent(2.05,2.1): %d\n",isRootPresent(2.05,2.1));
	printf("Result for isRootPresent(3.78,3.8): %d\n",isRootPresent(3.75,3.8));
	double array1[50]={0};
	findLowerBoundaries(array1,0.0,2.20);
	printf("Sample outout for findLowerBoundaries for 0.0,2.20:    \n");
	printArray(array1);
	double epsilon=0.00001;
	double roots[50]={0};
	findRoots(func,array1,roots,epsilon);
	printf("Sample output for findRoots for 0.0,2.20: \n");
	printArray(roots);
	printf("Sample output for leftRectangle for 1.4588,1.9677: \n");
	printf("%f",leftRectangle(func,1.4588,1.9677,0.00001));
	double integrals[50];
	double array2[50]={0};	
	saveIntegrals(array1,integrals,0.0,2.20,0.00001);
	
	printf("Test for saveIntegrals for 0.0,2.20\n");
	
	
	printArray(integrals);
	
	
	
}
