%module pyhdfeos

%{
    #define SWIG_FILE_WITH_INIT
    #include "pyhdfeos.h"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%apply ( float* ARGOUT_ARRAY1, int DIM1) {(float *datafield1data, int n)}

#include <mfhdf.h>
#include <hdf.h>
#include <HdfEosDef.h>
#include <stdio.h>
#include <stdlib.h>
%include "pyhdfeos.h"