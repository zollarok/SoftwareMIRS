
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "GateCtrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FBLed(struct FBLed* inst)
{
	 BOOL timer;
	{
		/*TODO: Add your code here*/
		switch(inst->State)
		{
			case ST_INIT:
				{
					inst->s1 = 0;

					inst->s2 = 0;

					inst->s3 = 0;

					inst->s4 = 0;
					
					break;
				}
			
			case ST_UNKNOWN:
				{
					timer = !timer;
					if (timer == 1)
					{
						inst->s1 = 1;

						inst->s2 = 1;

						inst->s3 = 1;

						inst->s4 = 1;
					}
					else
					{
						
						inst->s1 = 0;

						inst->s2 = 0;

						inst->s3 = 0;

						inst->s4 = 0;
					}
			
				}
		
			case ST_OPEN: 
				{
					inst->s1 = 0;

					inst->s2 = 0;

					inst->s3 = 0;

					inst->s4 = 0;

					break;
				}

			case ST_CLOSE: 
				{

					inst->s1 = 1;

					inst->s2 = 1;

					inst->s3 = 1;

					inst->s4 = 1;

					break;
				}

			case ST_ACC_POS: 
				{

					inst->s1 = 1;

					inst->s2 = 0;

					inst->s3 = 0;

					inst->s4 = 0;

					break;
				}

			case ST_ACC_NEG:
				{

					inst->s1 = 1;

					inst->s2 = 1;

					inst->s3 = 1;

					inst->s4 = 0;

					break;
				}

			case ST_NEG: 
				{

					inst->s1 = 1;

					inst->s2 = 1;

					inst->s3 = 0;

					inst->s4 = 0;

					break;
				}

			case ST_DEC_NEG:
				{

					inst->s1 = 1;

					inst->s2 = 0;

					inst->s3 = 0;

					inst->s4 = 0;

					break;
				}

			case ST_DEC_POS:
				{

					inst->s1 = 1;

					inst->s2 = 1;

					inst->s3 = 1;

					inst->s4 = 0;

					break;
				}

					case ST_POS: 
				{
						
					inst->s1 = 1;

					inst->s2 = 1;

					inst->s3 = 0;

					inst->s4 = 0;

					break;
				}
		}
	}
}


