
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{

}

void _CYCLIC ProgramCyclic(void)
{	
		sc0 = sw0;	
		sc1 = sw1;
		sc2 = sw2;
		sc3 = sw3;

}

void _EXIT ProgramExit(void)
{

}

