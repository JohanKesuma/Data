#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include "data_global.h"

extern "C" DATASHARED_EXPORT int factorial(const int &x);
extern "C" DATASHARED_EXPORT bool linearRegression(const double *x,
                                                   const double *y,
                                                   double *dest,
                                                   size_t);

#endif // DATAEXPORT_H
