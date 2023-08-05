// dllproject9.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "dllproject9.h"


// This is an example of an exported variable
DLLPROJECT9_API int ndllproject9=0;

// This is an example of an exported function.
DLLPROJECT9_API int fndllproject9(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Cdllproject9::Cdllproject9()
{
    return;
}
