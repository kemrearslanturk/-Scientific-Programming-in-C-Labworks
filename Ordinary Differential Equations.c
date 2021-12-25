#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fY(double x){
	double result1,result2;
	result1=pow(x,4)/4;
	result2=result1-(0.1*x);
	return exp(result2);
}
double fYdx(double x, double y){
	double result3;
	result3=(y*x*x*x)-(0.1*y);
	return result3;
}
void RK4(double (*fYdx)(double, double), double *yRK4, double xFirst, double yFirst, double
xLast, double stepSize)
{	
	
	double ta, tb, tc, td;
	*yRK4=yFirst;
	*yRK4++;
	for( ; xFirst <= xLast; xFirst = xFirst+stepSize)
	{
		ta = stepSize * fYdx(xFirst, yFirst);
		tb = stepSize * fYdx(xFirst+stepSize/2.0, yFirst+ta/2.0);
		tc = stepSize * fYdx(xFirst+stepSize/2.0, yFirst+tb/2.0);
		td = stepSize * fYdx(xFirst+stepSize, yFirst+tc);
		yFirst = yFirst + (ta +2.0* tb +2.0*tc + td)/6.0;
		*yRK4=yFirst;
		*yRK4++;
	}
	
}

void euler(double (*fYdx)(double, double), double *yEuler, double xFirst, double yFirst, double xLast, double stepSize)
{
	
	*yEuler=yFirst;
		*yEuler++;
		for( ; xFirst <= xLast; xFirst = xFirst+stepSize)
	{
	
		yFirst = yFirst + stepSize * fYdx(xFirst,yFirst);
		*yEuler=yFirst;
		*yEuler++;
	}

	/*
	return yFirst;*/
}

void midpoint(double (*fYdx)(double, double), double *yMidpoint, double xFirst, double
yFirst, double xLast, double stepSize){
		double ta,tb;
		
	*yMidpoint=yFirst;
	*yMidpoint++;
	for(;xFirst<=xLast;xFirst=xFirst+stepSize){
		ta = stepSize*fYdx(xFirst,	yFirst);
		tb = stepSize*fYdx(xFirst+stepSize/2.0, 	yFirst+ta/2.0);
			yFirst = 	yFirst+tb;
			*yMidpoint=yFirst;
	*yMidpoint++;
	}

}


int main(){
	double x0,y0,xlast,stepsize;
	int i;
	printf("Please enter x0: ");
	scanf("%lf",&x0);
	printf("Please enter y0: ");
	scanf("%lf",&y0);
	printf("Please enter xlast: ");
	scanf("%lf",&xlast);
	printf("Please enter stepsize: ");
	scanf("%lf",&stepsize);
	printf("%f",fY(0.2));
	printf("%f",fYdx(0.2,0.8));
	double *yEuler,*yMidpoint,*yRK4;
	yEuler= malloc((xlast-x0)/stepsize*sizeof(double));
	yMidpoint= malloc((xlast-x0)/stepsize*sizeof(double));
	yRK4= malloc((xlast-x0)/stepsize*sizeof(double));
	
	
	euler(fYdx,yEuler,x0,y0,xlast,stepsize);
	midpoint(fYdx,yMidpoint,x0,y0,xlast,stepsize);
	RK4(fYdx,yRK4,x0,y0,xlast,stepsize);
	
	
		for( i=0;i<=20;i++){
			printf("%f \t %f \t %f \t %f \n",yEuler[i],yMidpoint[i],yRK4[i],fY(i*stepsize));
	}


	
}
