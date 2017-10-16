#include "Complex.h"
#include <cmath>

Complex freqResponse(double w)
{
    Complex c1(0.0, 200), c2(2.0, w), c3(w*w*w), c4(1.0, 0.1*w), c5(1.0, 0.3*w), c6(1.0, 0.6*w), c7(1.0, 0.8*w);

    return c1*c2/(c3*c4*c5*c6*c7);
}