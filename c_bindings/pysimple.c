#include <Python.h>

float square(float x) {
    return x*x;
}

/* C reminder: static means only visible in this file (not exported) */
static PyObject* square_wrapper(PyObject* self, PyObject* args) {
  float input;
  float result;
  PyObject* ret;

  /* parse arguments */
  if (!PyArg_ParseTuple(args, "f", &input)) {
    return NULL;
  }

  /* run the actual function */
  result = square(input);

  /* build the resulting string into a Python object. */
  ret = PyFloat_FromDouble(result);

  return ret;
}

static PyMethodDef PySimpleMethods[] = {
 { "square", square_wrapper, METH_VARARGS, "Square function" },
 { NULL, NULL, 0, NULL }
};

DL_EXPORT(void) initpysimple(void)
{
  Py_InitModule("pysimple", PySimpleMethods);
}

