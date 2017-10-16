#include <iostream>
#include "Euler.h"

void EulerSolve(funct_ptr f, double U0, double T, int n, vector<double> &u, vector<double> &t)
{
    double dt = T / n;

    t[0] = 0.0;
    u[0] = U0;
    for (int i = 0; i < n; i++)
    {
        t[i + 1] = t[i] + dt;
        u[i + 1] = u[i] + dt * f(u[i], t[i]);
    }
}
