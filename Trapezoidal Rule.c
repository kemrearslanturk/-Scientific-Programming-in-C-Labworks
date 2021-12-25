#include <stdio.h>
#include <math.h>
double func(double x,double sigma ){
	double result1,result2,result;
	result1=-1*(x*x)/(sigma*sigma);
	result2=exp(result1);
	result=(1/sigma)*result2;
	return result;
}

double trapezoidal(
double a,/*starting x*/
double b,/*ending x*/
double sigma1,
int n /* number of panels*/
)
{
	double answer,h; /*result and panel width*/
	int i; /*counter for intervals*/
	answer=func(a,sigma1)/2;
	h=(b-a)/n;
	/*sum panel areas*/
	for(i=1; i<=n; i++)
	answer= answer + func(a+i*h,sigma1);
	
	answer= answer-func(b,sigma1)/2;
	return(h*answer);
}
double newfunc(sigma){
	return(-2/(sigma*sigma*sigma));
}
double error(double a,double b,double n,double sigma){

    double result;
    double fdd=-2/(sigma*sigma*sigma);
    result=-pow(b-a,3)/(12*n*n)*fdd;
    return result;
}
double adapt(
double a, /*starting x*/
double b,/*ending x*/
int n0, /*number of panels*/
double tolerance,/*measure of convergence*/
int sigma,
int *count
)
{
	double check=tolerance+1.0;
	double lowval,val;
	lowval=trapezoidal(a,b,sigma,n0);
	while(check>tolerance){
		n0=2*n0;
		val=trapezoidal(a,b,sigma,n0);
		check=error(a,b,n0,sigma);
		lowval=val;
	}
	*count=n0;
	return(val);
}


int main(){
	double x_start_test = 0;
	double sigma_test = 4;
	printf("Test for bell function: %f\n",func( x_start_test,sigma_test));
	double num_panel_test = 10;
	double x_end_test = 20;
	printf("Test for trapezoidal function: %f\n",trapezoidal(0,20,4,10));
	int n;
	int sigma;
	float tolerance;
/*
	double result=adapt(0,30,1,0.1,1,&n);
	printf("%f",result); 
	printf()
	printf("%d",n);*/
 while(1){

    printf("Enter the sigma values:");
    scanf("%d",&sigma); 
    if(sigma==0){
        break;
    }
    else{
	
    printf("Enter the tolerance values:");
    scanf("%lf",&tolerance); 
	double result1=adapt(0,30,1,0.1,1,&n);
	printf("Result: %lf",result1); 
		printf("Number of panel: %d\n",n);
	double result2=adapt(0,30,1,0.1,2,&n);
	printf("Result: %lf",result2); 
		printf("Number of panel: %d\n",n);
	double result3=adapt(0,30,1,0.1,4,&n);
	printf("Result: %lf",result3); 
		printf("Number of panel: %d\n",n);
	double result4=adapt(0,30,1,0.1,10,&n);
	printf("Result: %lf",result4); 

	printf("Number of panel: %d",n);

    }
}
}
    	
  

    


