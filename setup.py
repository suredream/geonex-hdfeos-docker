#! /usr/bin/env python
# https://scipy-cookbook.readthedocs.io/items/SWIG_NumPy_examples.html

# System imports
from distutils.core import *
from distutils      import sysconfig

# Third-party modules - we depend on numpy for everything
import numpy

# Obtain the numpy include directory.  This logic works across numpy versions.
try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()

# pyhdfeos extension module
_pyhdfeos = Extension("_pyhdfeos",
                   ["pyhdfeos.i","pyhdfeos.c"],
                   include_dirs = [numpy_include, '/usr/include', '/usr/local/include/'],
                   library_dirs=['/usr/local/lib'],
                   libraries=['hdfeos', 'Gctp','mfhdf','df','jpeg','z','m'],
                #    extra_compile_args=["-fPIC"],
                   )

# pyhdfeos setup
setup(  name        = "pyhdfeos package",
        description = "Python wrapper sample of HDFEOS using swig",
        author      = "Jun Xiong",
        version     = "0.1",
        ext_modules = [_pyhdfeos]
        )