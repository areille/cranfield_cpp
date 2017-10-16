#include <iostream>
#include <iomanip>
#include <cmath>
#include "Euler.h"
#include "RungeKutta.h"

int main()
{
    double U0, T;
    int n;

    try
    {
        std::cout << "input initial conditions\n";
        std::cin >> U0;

        std::cout << "input the range for T (0,T)\n";
        std::cin >> T;

        std::cout << "input the number of steps\n";
        std::cin >> n;

        // allocate the t and u arrays
        vector<double> t(n + 1), u(n + 1);

        // call the eulersolve function
        // EulerSolve(f, U0, T, n, u, t);
        RungeKuttaSolve(f, U0, T, n, u, t);

        // output the results
        std::cout << "Solution to u’ = u, " << 0 << " <= t <= " << T << ", step size " << T / n << "\n";
        std::cout << "*********************************************************\n";
        std::cout << "t " << std::setw(30) << "u(t)" << std::setw(20) << "exact_soln" << std::setw(25) << "| u(t) – exact_soln |\n";
        std::cout << std::fixed << std::setprecision(7);
        for (int i = 0; i <= n; i++)
        {
            std::cout << t[i] << std::setw(25) << u[i] << std::setw(20) << exp(t[i]) << std::setw(20) << fabs(u[i] - exp(t[i])) << "\n";
        }
    }
    catch (std::exception &e)
    {
        // Catching other errors
        std::cerr << "std::exception caught" << std::endl;
        std::cerr << "Type: " << typeid(e).name() << std::endl;
        std::cerr << "What: " << e.what() << std::endl;
    }
    return 0;
}

double f(double u, double t)
{
    return u;
}