
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "MotorCntrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	/*TODO: Add your code here*/
	inst->integrator.dt = inst->dt;
	inst->integrator.in = ((inst->u)/(inst->ke) - (inst->w))*\
		(1/(inst->Tm));
	FB_Integrator(&(inst->integrator));
	inst->w = inst->integrator.out;
	inst->integrator.in = inst->w;
	inst->integrator.out = inst->phi;
	FB_Integrator(&(inst->integrator));
	inst->phi = inst->integrator.out;
	inst->integrator.out = inst->w;
}
