#include <stdio.h>
#include "complex.h"
void freqResponse(double f, double* p_r, double* p_i, double* p_m);

#define PI 3.14159


int main()
{
	double re, im, mag;
	int i;
	
	printf("Frequency response for feedback system\n");
	printf("***************************************\n");
	printf("Frequency \t Real part \t Imaginary part \t Magnitude\n");
	
	for (i=1; i<=10; i++) {
		freqResponse((double)i,&re,&im,&mag);
		printf("%lf \t %lf \t %lf \t %lf\n",(double)i,re,im,mag);
	}

	return 0;
}


/* p_r, _i, p_m are pointers to doubles. You need to use pointers
to get values out of a function when you are using the parameter list */

void freqResponse(double f, double* p_r, double* p_i, double* p_m)
{
	fcomplex z;
	double re, im, mag;
	fcomplex a, b, top;
	fcomplex c, d, e, f1, g, bottom;
	double w = 2*PI*f;

	/* write the code that computes z = G(2*PI*f) according to the formula */
	
	/* top part */
	a = Complex(0,200);
	b = Complex(2,w);
	top = Cmul(a,b);

	/* bottom part */
	c = Complex(w*w*w,0);
	d = Complex(1,0.1*w);
	e = Complex(1,0.3*w);
	f1 = Complex(1,0.6*w);
	g = Complex(1,0.8*w);

	bottom = Cmul(c,Cmul(d,Cmul(e,Cmul(f1,g))));

	z = Cdiv(top,bottom);

	/* we then extract the real, imaginary and magnitude values of z */
	re = z.r;
	im = z.i;
	mag = Cabs(z);

	/* this is how we copy the real, imaginary and magnitude values
	into the pointers p_r, p_i, p_m */
	*p_r = re;
	*p_i = im;
	*p_m = mag;	
}
