#include "Euler.h"

Euler::Euler() : f(0), U0(0), T(0), n(0) {}

Euler::Euler(func_ptr f, double U0, double T, int n)
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

vector<double> Euler::get_t() const
{
    return t;
}

vector<double> Euler::get_u() const
{
    return u;
}

void Euler::solve()
{
    u[0] = U0;
    // initial condition
    for (int k = 1; k <= n; k++)
    {
        u[k] = advance(k - 1);
    }
}

double Euler::advance(int k) const
{
    return u[k] + dt * f(u[k], t[k]);
}