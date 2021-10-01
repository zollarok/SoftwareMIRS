
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
REAL V_lim(REAL in, REAL max_in)
{
	if ((in >= max_in) || (in <= -max_in))
	{
		if (in>0)
			return max_in;
		else
			return -max_in;
	}
	else
		return in;
}
void FB_Regulator(struct FB_Regulator* inst)
{
	/*TODO: Add your code here*/
	REAL temp;
	inst->integrator.dt = inst->dt;
	inst->integrator.in = ((inst->e*inst->k_i)+inst->ivOld);
	FB_Integrator(&(inst->integrator));
	temp = inst->integrator.out + V_lim((inst->e)*(inst->k_p),inst->max_abs_value);
	inst->u = V_lim(temp, inst->max_abs_value);
	inst->ivOld = inst->u - temp;
}
