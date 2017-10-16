#include <vector>
using namespace std;

typedef double (*funct_ptr)(double u, double t);
double f(double u, double t);
void RungeKuttaSolve(funct_ptr f, double U0, double T, int n,
    vector<double> &u, vector<double> &t);