#include <stdio.h>
#include <math.h>

#define SIZE 50
#define PI 3.14159

/* function prototypes for complex arithmetic */

typedef struct FCOMPLEX {double r,i;} fcomplex;

fcomplex Cadd(fcomplex a,fcomplex b);
fcomplex Csub(fcomplex a,fcomplex b);
fcomplex Cmul(fcomplex a,fcomplex b);
fcomplex Complex(double re,double im);
fcomplex Conjg(fcomplex z);
fcomplex Cdiv(fcomplex a,fcomplex b);
double Cabs(fcomplex z);
fcomplex Inverse(fcomplex z);
fcomplex RCmul(double x,fcomplex a);
void print(fcomplex z);

void dft(fcomplex x[], int N, fcomplex* y, int n);
void inv_dft(fcomplex y[], int N, fcomplex* x, int k);


int main()
{
	fcomplex x[SIZE];
	fcomplex y[SIZE];
	int N;
	int i;

	printf("input the size of the complex array x\n");
	scanf("%d",&N);
	printf("please input the %d complex numbers\n",N);
	for (i=0; i<N; i++) scanf("%lf %lf",&x[i].r,&x[i].i);
	/* call the DFT function */
	for (i=0; i<N; i++) DFT(x,N,&y[i],i);
	/* call the inverse DFT function */
	for (i=0; i<N; i++) Inv_DFT(y,N,&x[i],i);

	/* print the resulting array of complex numbers x */
	for (i=0; i<N; i++) print(x[i]);

	return 0;
}


void dft(fcomplex x[], int N, fcomplex* y, int n) 
{
	fcomplex sum = Complex(0.0,0.0);
	fcomplex temp;
	int k;

	for (k=0; k<N; k++) {
		temp = Complex(cos(2.0*PI*k*n/N),-sin(2.0*PI*k*n/N));
		sum = Cadd(sum,Cmul(x[k],temp));
	}

	sum = RCmul(1.0/N,sum);

	*y = Complex(sum.r,sum.i);
}

void inv_dft(fcomplex y[], int N, fcomplex* x, int k) 
{
	fcomplex sum = Complex(0.0,0.0);
	fcomplex temp;
	int n;

	for (n=0; n<N; n++) {
		temp = Complex(cos(2.0*PI*k*n/N),sin(2.0*PI*k*n/N));
		sum = Cadd(sum,Cmul(y[n],temp));
	}

	*x = Complex(sum.r,sum.i);
}


fcomplex Cadd(fcomplex a,fcomplex b)
{	
	fcomplex c;
	c.r=a.r+b.r;
	c.i=a.i+b.i;
	return c;
}

fcomplex Csub(fcomplex a,fcomplex b)
{	
	fcomplex c;

	c.r = a.r-b.r;
	c.i = a.i-b.i;
	return c;
}

fcomplex Cmul(fcomplex a,fcomplex b)
{	
	fcomplex c;

	c.r = a.r*b.r - a.i*b.i;
	c.i = a.r*b.i + a.i*b.r;

	return c;
}

fcomplex Complex(double re,double im)
{	
	fcomplex c;
	c.r=re;
	c.i=im;
	return c;
}

fcomplex Conjg(fcomplex z)
{	
	fcomplex c;
	c.r = z.r;
	c.i = -z.i;
	return c;
}


fcomplex Inverse(fcomplex z)
{
	fcomplex c;

	c.r = z.r/(z.r*z.r+z.i*z.i);
	c.i = -z.i/(z.r*z.r+z.i*z.i);

	return c;
}


fcomplex Cdiv(fcomplex a,fcomplex b)
{	
	fcomplex c;

	c = Cmul(Inverse(b),a);

	return c;
}

double Cabs(fcomplex z)
{	
	double ans;

	ans = sqrt(z.r*z.r+z.i*z.i);
	
	return ans;
}

fcomplex RCmul(double x,fcomplex a)
{	
	fcomplex c;
	
	c.r=x*a.r;
	c.i=x*a.i;
	
	return c;
}

void print(fcomplex z)
{
	printf("the complex number is %lf + i %lf\n",z.r,z.i);
}
