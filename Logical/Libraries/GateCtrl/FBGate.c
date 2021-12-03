
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
void FBGate(struct FBGate* inst)
{
	switch (inst->State) {
		case ST_INIT: //
			inst->State = ST_UNKNOWN;
			break;
		case ST_UNKNOWN: //
			if ((inst->direction == 0) && (inst->sw0 == 0)){
			inst->State = ST_OPEN;
			}
			if ((inst->direction == 1) && (inst->sw0 == 1)){
				inst->State = ST_CLOSE;
			}
			break;
		case ST_OPEN: //
			inst->DriveBlk.enable = 0;
			FBX64Inverter(&inst->DriveBlk);
			inst->Speed = 0;
			FBX64Inverter(&inst->DriveBlk);
			if (inst->direction == 1){
				inst->State = ST_ACC_POS;
			}
			break;
		case ST_CLOSE: 
			inst->DriveBlk.enable = 0;
			FBX64Inverter(&inst->DriveBlk);
			inst->Speed = 0;
			FBX64Inverter(&inst->DriveBlk);
			if (inst->direction == 0){
				inst->State = ST_ACC_NEG;
			}
			break;
		case ST_ACC_POS: 
			inst->DriveBlk.enable = 1;
			inst->Speed = 100;
			FBX64Inverter(&inst->DriveBlk);
			if (inst->sw1){
				inst->State = ST_POS;
			}
			if (inst->direction == 0) {
				inst->State = ST_ACC_NEG;
			}	
			break;
		case ST_ACC_NEG:
			inst->DriveBlk.enable = 1;
			FBX64Inverter(&inst->DriveBlk);
			inst->Speed = -100;
			if (!inst->sw2){
				inst->State = ST_NEG;
			}
			break;
		case ST_NEG: 
			inst->Speed = -300;
			FBX64Inverter(&inst->DriveBlk);
			if (!inst->sw1){
				inst->State = ST_DEC_NEG;
			}
			break;
		case ST_DEC_NEG: 
			inst->Speed = -100;
			FBX64Inverter(&inst->DriveBlk);
			if (!inst->sw0){
				inst->State = ST_OPEN;
			}
			break;
		case ST_DEC_POS: 
			FBX64Inverter(&inst->DriveBlk);
			inst->Speed = 100;
			if (inst->sw3){
				inst->State = ST_CLOSE;
			}
			break;
		case ST_POS: 
			FBX64Inverter(&inst->DriveBlk);
			inst->Speed = 300;
			if (inst->sw2){
				inst->State = ST_DEC_POS;
			}
			if (inst->direction == 0) {
				inst->State = ST_NEG;
			}
			break;
	}
}
