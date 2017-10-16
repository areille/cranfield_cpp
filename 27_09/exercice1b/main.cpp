#include "matrix.h"

int main()
{
    // std::ifstream ifs("matrix.dat");

    Matrix m, m1;
    Vector v;

    // ifs >> m;

    std::cin >> m;
    std::cin >> m1;
    std::cin >> v;

    double one_norm, two_norm, uniform_norm;

    one_norm = m.one_norm();
    two_norm = m.two_norm();
    uniform_norm = m.uniform_norm();

    std::cout << "The three norms are : \n"
              << std::endl;
    std::cout << "one norm : " << one_norm << "\n";
    std::cout << "two norm : " << two_norm << "\n";
    std::cout << "uniform norm : " << uniform_norm << "\n";

    std::cout << m1 * m;

    std::cout << m * v;

    return 0;
}