#include "Complex.h"
#include <math.h>

#define PI 3.14159

Complex dft(Complex x[], int N, int n)
{
    Complex sum = Complex(0.0, 0.0);
    Complex temp;

    int k;

    for (k = 0; k < N; k++)
    {
        temp = x[k] * Complex(cos(2.0 * PI * k * n / N), -sin(2.0 * PI * k * n / N));
        sum += temp;
    }

    Complex div = Complex(N);

    return sum / div;
}

Complex inv_dft(Complex y[], int N, int k)
{
    Complex sum = Complex(0.0, 0.0);
    Complex temp;
    int n;

    for (n = 0; n < N; n++)
    {
        temp = y[k] * Complex(cos(2.0 * PI * k * n / N), sin(2.0 * PI * k * n / N));
        sum += temp;
    }
    Complex div = Complex(N);

    return sum / div;
}