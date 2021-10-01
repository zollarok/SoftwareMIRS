
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_regulator.k_p = 66.7;
	fb_regulator.k_i = 1666.7;
	fb_regulator.ivOld = 0;
	fb_regulator.max_abs_value = 4000;
	fb_regulator.dt = 0.002;
	fb_regulator.e = 0;
	fb_regulator.u = 0;
		
	fb_motor.Tm = 0.04;
	fb_motor.ke = 10;
	fb_motor.dt = 0.002;
	fb_motor.u = 0;
	fb_motor.w = 0;
	fb_motor.phi = 0;
	
	fb_motor2.Tm = 0.04;
	fb_motor2.ke = 10;
	fb_motor2.dt = 0.002;
	fb_motor2.u = 0;
	fb_motor2.w = 0;
	fb_motor2.phi = 0;
	
	counter = 0;
	Speed = 0;
	Enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	counter+=1;
	Speed = (counter <= 200)?60:0;
	if (counter == 1000)
	{
		counter = 0;	
	}
	if (Enable)
	{
		fb_regulator.e = Speed - fb_motor.w;
		FB_Regulator(&fb_regulator);
		fb_motor.u = fb_regulator.u;
		FB_Motor(&fb_motor);
		
		fb_motor2.u = Speed - fb_motor2.w;
		FB_Motor(&fb_motor2);
	}
}

void _EXIT ProgramExit(void)
{

}

