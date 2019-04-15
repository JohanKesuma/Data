#include "dataexport.h"
#include "data.h"

int factorial(const int &x)
{
    return Data::factorial(x);
}

bool linearRegression(const double *x, const double *y, double *dest, size_t size)
{
    return Data::linearRegression(x, y, dest, size);
}
