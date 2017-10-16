#include "matrix.h"
#include "vector.h"
#include "lu.h"
#include "math.h"

void lu_fact(const Matrix &a, Matrix &l, Matrix &u, int n)
{

    Matrix temp;
    double mult;
    int i, j, k;

    temp = Matrix(n, n);

    temp = a;

    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            if (fabs(temp[k][k]) < 1.e-07)
            {
                std::cout << "pivot is zero" << std::endl;
                exit(1);
            }
            mult = temp[i][k] / temp[k][k];
            temp[i][k] = mult;
            for (j = k + 1; j < n; j++)
            {
                temp[i][j] -= mult * temp[k][j];
                if (fabs(temp[i][i]) < 1.e-07)
                {
                    std::cout << "Pivot is zero" << std::endl;
                    exit(1);
                }
            }
        }
    }
    // create l and u from temp
    for (i = 0; i < n; i++)
    {
        l[i][i] = 1.0;
    }
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            l[i][j] = temp[i][j];

    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            u[i][j] = temp[i][j];
}

void lu_solve(const Matrix &l, const Matrix &u, const Vector &b, int n, Vector &x)
{
    Vector temp;
    int i, j;

    temp = Vector(n);

    temp = b;

    for (i = 0; i < n; i++)
        for (j = 0; j < i; j++)
            temp[i] -= l[i][j] * temp[j];

    for (i = n - 1; i >= 0; i--)
    {
        for (j = i + 1; j < n; j++)
            temp[i] -= u[i][j] * temp[j];
        temp[i] /= u[i][i];
    }
    for (i = 0; i < n; i++)
        x[i] = temp[i];
}

void reorder(const Matrix &a, int n, Matrix &p)
{
    int i, j, k;
    int pvtk, pvti;
    Vector scale;
    double aet, tmp, mult;
    Matrix temp;

    std::vector<int> pvt(n);
    temp = Matrix(n, n);
    temp = a;

    for (k = 0; k < n; k++)
        pvt[k] = k;
    scale = Vector(n);
    for (k = 0; k < n; k++)
    {
        scale[k] = 0;
        for (j = 0; j < n; j++)
            if (fabs(scale[k] < fabs(temp[k][j])))
                scale[k] = fabs(temp[k][j]);
    }

    for (k = 0; k < n - 1; k++)
    {
        int pc = k; 
        aet = fabs(temp[pvt[k]][k] / scale[k]);
        for (i = k + 1; i < n; i++)
        {
            tmp = fabs(temp[pvt[i]][k] / scale[pvt[i]]);
            if (tmp > aet)
            {
                aet = tmp;
                pc = i;
            }
        }
        if (fabs(aet) < 1.e-07)
        {
            printf("pivot is zero\n");
            exit(1);
        }
        if (pc != k)
        { // swap pvt[k] and pvt[pc]
            int ii = pvt[k];
            pvt[k] = pvt[pc];
            pvt[pc] = ii;
        }

        // now eliminate the column entries logically below mx[pvt[k]][k]
        pvtk = pvt[k]; // pivot row
        for (i = k + 1; i < n; i++)
        {
            pvti = pvt[i];
            if (temp[pvti][k] != 0)
            {
                mult = temp[pvti][k] / temp[pvtk][k];
                temp[pvti][k] = mult;
                for (j = k + 1; j < n; j++)
                    temp[pvti][j] -= mult * temp[pvtk][j];
            }
        }
    }
    for (i=0; i<n; i++) p[i][pvt[i]]=1.0;
}