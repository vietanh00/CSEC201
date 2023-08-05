// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLPROJECT9_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLPROJECT9_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLPROJECT9_EXPORTS
#define DLLPROJECT9_API __declspec(dllexport)
#else
#define DLLPROJECT9_API __declspec(dllimport)
#endif

// This class is exported from the dll
class DLLPROJECT9_API Cdllproject9 {
public:
	Cdllproject9(void);
	// TODO: add your methods here.
};

extern DLLPROJECT9_API int ndllproject9;

DLLPROJECT9_API int fndllproject9(void);
