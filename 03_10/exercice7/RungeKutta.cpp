#include "RungeKutta.h"


void RungeKuttaSolve(funct_ptr f, double U0, double T, int n, vector<double> &u, vector<double> &t)
{
    double dt = T / n;

    t[0] = 0.0;
    u[0] = U0;
    for (int i = 0; i < n; i++)
    {
        t[i + 1] = t[i] + dt;
        double k1 = dt * f(u[i], t[i]);
        double k2 = dt * f(u[i] + 0.5 * k1, t[i] + 0.5 * dt);
        double k3 = dt * f(u[i] + 0.5 * k2, t[i] + 0.5 * dt);
        double k4 = dt * f(u[i] + k3, t[i] + dt);

        u[i + 1] = u[i] + (1.0/6.0) * (k1 + (2 * k2) + (2 * k3) + k4);
    }
}