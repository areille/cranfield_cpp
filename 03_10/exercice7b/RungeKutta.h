#include <vector>
typedef double (*func_ptr)(double x, double y);
double f(double u, double t);
using namespace std;
class RungeKutta
{
  private:
    func_ptr f;                  // function f(u,t)
    double U0;                   // initial condition
    double T;                    // time interval (0,T)
    int n;                       // number of time steps
    std::vector<double> t;       // time steps vector
    std::vector<double> u;       // solution values vector
    double dt;                   // time step
    double advance(int k) const; // advance the solution one time step
  public:
    RungeKutta();
    RungeKutta(func_ptr f, double U0, double T, int n);
    void solve();
    vector<double> get_t() const; // return the t array
    vector<double> get_u() const; // return the u array
};