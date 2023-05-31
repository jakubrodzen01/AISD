#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 1000000

double c_od,c_do;

double f3(double x)
{
	double y;
	y = exp(x);
 return y;      
}      
double f4(double x) 
{
	double y;
	y = (x-2)/(2*x*x+3*x-14);
 return y;
}


double prostokaty(double( *f)(double))
{
	double krok, p, suma=0;
	krok=(c_do-c_od)/lp;
	for(p=c_od; p<c_do; p+=krok)
		suma+=(*f)(p+krok)*krok;
               
	return suma;      
}

double trapezy(double (*f)(double))
{
	double krok, p, suma=0;
	krok=(c_do-c_od)/lp;
	for(p=c_od; p<c_do; p+=krok)
		suma+=((*f)(p)+(*f)(p+krok))/2*krok;
	
	return suma;
}
       
double mc(double(*f)(double))
{
	double krok, x, y, zakres, MAX=0, MIN=0, p, N, No=0, suma=0, pole;
	krok=(c_do-c_od)/lp;
	N=lp;
	
	for(p=c_od; p<=c_do; p+=krok)
		if((*f)(p)>MAX)
			MAX=(*f)(p);
		else if((*f)(p)<MIN)
			MIN=(*f)(p);
			
	srand(time(NULL));
	zakres=c_do-c_od;
	double ff;
	
	for(p=0; p<N; p++)
	{
		x=(double)rand();
		x=x/RAND_MAX*zakres+c_od;
		y=(double)rand();
		y=y/RAND_MAX*(MAX-MIN)+MIN;
		
		ff=(*f)(x);
		
		if(ff>y && y>0)
			No++;
		else if(ff<y && y<0)
			No--;
	}
	
	pole=(MAX-MIN)*(c_do-c_od);
	suma=No/N*pole;
	
 	return suma;
}
