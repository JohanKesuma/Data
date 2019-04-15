#ifndef DATA_H
#define DATA_H

#include "Python.h"
#include "data_global.h"

class Data
{

public:
    Data();
    static int factorial(const int &x);
    static bool linearRegression(const double *x, const double *y, double *dest, size_t size);

};

#endif // DATA_H
