#include <iostream>
#include "Complex.h"
#include "dft.h"

int main()
{
    Complex x[40], y[40], z[40];
    Complex* w;
    int N, i;

    std::cout << "Input the size of the array x \n";
    std::cin >> N;
    w = new Complex[N];
    std::cout << "Please input the" << N << "complex numbers\n";
    for (i=0; i<N; i++) {
        std::cin >> w[i];
    }
    for (i=0; i<N; i++) {
        y[i] = dft(w, N, i);
    }
    for (i=0; i<N; i++) {
        z[i] = inv_dft(w, N, i);
    }
    for (i=0; i<N; i++) {
        std::cout << y[i] << "  " << w[i] << std::endl;
    }
    

    return 0;
}