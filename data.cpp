#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL calc_ARRAY_API

#include "data.h"
#include "numpy/arrayobject.h"

Data::Data()
{

}

int Data::factorial(const int &x)
{
    int res = 0;
    PyObject *matematikaModuleName = PyUnicode_FromString("lib.python.matematika");
    PyObject *matematikaModule = PyImport_Import(matematikaModuleName);
    Py_DECREF(matematikaModuleName);
    PyObject *pFunc = PyObject_GetAttrString(matematikaModule, "factorial");
    if (PyCallable_Check(pFunc)) {
        PyObject *num = PyLong_FromLong(x);
        PyObject *args = PyTuple_Pack(1, num);

        PyObject *pValue = PyObject_CallObject(pFunc, args);

        res = PyLong_AsLong(pValue);

        Py_DECREF(num);
        Py_DECREF(args);
        Py_DECREF(pValue);
        Py_DECREF(pFunc);
    }
    Py_DECREF(matematikaModule);

    return res;
}

bool Data::linearRegression(const double *x, const double *y, double *dest, size_t size)
{
    PyObject *matematikaModuleName = PyUnicode_FromString("lib.python.matematika");
    PyObject *matematikaModule = PyImport_Import(matematikaModuleName);
    Py_DECREF(matematikaModuleName);
    PyObject *pFunc = PyObject_GetAttrString(matematikaModule, "getLinearReg");
    if (PyCallable_Check(pFunc)) {
        npy_intp dim = size;
        PyObject *pyXArray = PyArray_SimpleNewFromData(1, &dim, NPY_DOUBLE, (void*)x);
        PyObject *PyYArray = PyArray_SimpleNewFromData(1, &dim, NPY_DOUBLE, (void*)y);
        PyObject *args = PyTuple_Pack(2, pyXArray, PyYArray);

        PyObject *pResult = PyObject_CallObject(pFunc, args);
        PyObject *pyM = PyDict_GetItemString(pResult, "m");
        PyObject *pyC = PyDict_GetItemString(pResult, "c");

        dest[0] = PyFloat_AsDouble(pyM);
        dest[1] = PyFloat_AsDouble(pyC);

        // cleaning
        Py_DECREF(pyM);
        Py_DECREF(pyC);
        Py_DECREF(args);
        Py_DECREF(pResult);
        Py_DECREF(pFunc);
        return true;
    }
    Py_DECREF(matematikaModule);

    return false;
}

