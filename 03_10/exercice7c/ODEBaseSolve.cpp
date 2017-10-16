#include "ODEBaseSolve.h"

ODEBaseSolve::ODEBaseSolve() : f(0), U0(0), T(0), n(0) {}

ODEBaseSolve::ODEBaseSolve(func_ptr f, double U0, double T, int n)
{
    this->f = f;
    this->U0 = U0;
    this->T = T;
    this->n = n;

    this->t = vector<double>(n + 1);
    this->u = vector<double>(n + 1);
    this->dt = T / n;

    t[0] = 0.0;
    for (int i = 0; i <= n; i++)
        t[i + 1] = t[i] + dt;
}

void ODEBaseSolve::solve()
{
    u[0] = U0;
    for (int k = 1; k <= n; k++)
        u[k] = advance(k - 1);
}

vector<double> ODEBaseSolve::get_t() const
{
    return t;
}
vector<double> ODEBaseSolve::get_u() const
{
    return u;
}

EulerSolve::EulerSolve() : ODEBaseSolve() {}

EulerSolve::EulerSolve(func_ptr f, double U0, double T, int n) : ODEBaseSolve(f, U0, T, n)
{
}

double EulerSolve::advance(int k) const
{
    return u[k] + dt * f(u[k], t[k]);
}

RungeKuttaSolve::RungeKuttaSolve() : ODEBaseSolve() {}

RungeKuttaSolve::RungeKuttaSolve(func_ptr f, double U0, double T, int n) : ODEBaseSolve(f, U0, T, n)
{
}

double RungeKuttaSolve::advance(int k) const
{
    double k1 = dt * f(u[k], t[k]);
    double k2 = dt * f(u[k] + 0.5 * k1, t[k] + 0.5 * dt);
    double k3 = dt * f(u[k] + 0.5 * k2, t[k] + 0.5 * dt);
    double k4 = dt * f(u[k] + k3, t[k] + dt);
    return u[k] + (1.0 / 6.0) * (k1 + (2 * k2) + (2 * k3) + k4);
}