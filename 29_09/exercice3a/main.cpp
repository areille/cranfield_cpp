#include <iostream>
#include "matrix.h"
#include "vector.h"
#include "lu.h"

int main()
{
    Matrix A;
    Vector b;

    std::cout << "Matrix A :\n";
    std::cin >> A;
    std::cout << "Vector b : \n";
    std::cin >> b;

    Matrix l = Matrix(A.getNrows(), A.getNcols());
    Matrix u = Matrix(A.getNrows(), A.getNcols());
    Vector x = Vector(b.getSize());

    Matrix p =  Matrix(A.getNrows(), A.getNcols());
    // lu_fact(A, l, u, A.getNcols());
    lu_fact(p*A, l, u, A.getNcols());
    Vector pb = p*b;
    
    lu_solve(l, u, b, l.getNcols(), x);

    std::cout << "matrix L :" << l << " ";
    std::cout << "matrix u :" << u << " ";
    std::cout << "vector x :" << x << " ";

    return 0;
}