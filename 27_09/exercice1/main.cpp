#include <iostream>
#include "vector.h"

int main()
{
    Vector v;

    // std::cin >> v;

    std::ifstream ifs("vector.dat");

    ifs >> v;

    std::cout << "Please input the norm you require\n";
    std::cout << "type 0 for 1 norm, 1 for 2 norm, 2 for uniform norm\n";

    int choice;
    double result;

    std::cin >> choice;

    switch (choice)
    {
    case 0:
        result = v.one_norm();
        break;
    case 1:
        result = v.two_norm();
        break;
    case 3:
        result = v.uniform_norm();
        break;
    default:
        std::cout << "incorrect choice motherfucker, please try again";
        break;
    }

    std::cout << "the" << choice << "norm is" << result;

    return 0;
}
